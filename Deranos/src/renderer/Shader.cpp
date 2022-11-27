#include "pch.h"
#include "Shader.h"


Shader::Shader(const char* vertexPath, const char* fragmentPath)
    :m_depth_func(ECompareFuncs::LESS), m_write_depth(true), m_cull_func(ECullFuncs::CCW)
{
    // 1. retrieve the vertex/fragment source code from filePath
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    // ensure ifstream objects can throw exceptions:
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        // open files
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;
        // read file's buffer contents into streams
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        // close file handlers
        vShaderFile.close();
        fShaderFile.close();
        // convert stream into string
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (std::ifstream::failure& e)
    {
        DERANOS_CORE_ERROR(std::strcat("ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ: " , e.what()));
    }
    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();
    // 2. compile shaders
    unsigned int vertex, fragment;
    // vertex shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    CheckCompileErrors(vertex, "VERTEX");
    // fragment Shader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    CheckCompileErrors(fragment, "FRAGMENT");
    // shader Program
    m_id = glCreateProgram();
    glAttachShader(m_id, vertex);
    glAttachShader(m_id, fragment);
    glLinkProgram(m_id);
    CheckCompileErrors(m_id, "PROGRAM");
    // delete the shaders as they're linked into our program now and no longer necessary
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::Bind(Texture& texture)
{
    glUseProgram(m_id);
    DepthFunc();
    CullFunc();
    BindSampler(texture, "T_DIFFUSE", USERMAP_DIFFUSE);//for each texture bind
}

void Shader::Bind(Texture& texture, Camera& camera, Transform& model_xform)
{
    Bind(texture);
    SetMat4("model", model_xform.GetMatrix());
    SetMat4("view", camera.GetViewMatrix());
    SetMat4("projection", camera.GetProjectionMatrix());
}

void Shader::BindSampler(Texture& texture, const char* texture_name, int texture_slot)
{
    m_sampler = std::make_shared<Sampler>(texture, texture_slot, EWrapMode::Wrap, EFilteringMode::LinearMipLinear, EMaxAnisotropyLevel::High);
    SetInt(texture_name, texture_slot);
}

void Shader::SetCullFunc(ECullFuncs cull_func)
{
    m_cull_func = cull_func;
}

void Shader::SetDepthFunc(ECompareFuncs depth_func, bool write_depth)
{
    m_depth_func = depth_func;
    m_write_depth = write_depth;
}

void Shader::DepthFunc()
{
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(int(m_depth_func));

    if(m_write_depth)
        glDepthMask(GL_TRUE);
    else
        glDepthMask(GL_FALSE);
}

void Shader::StencilFunc(ECompareFuncs stencil_func, int ref, int read_mask, int write_mask, EStencilOps stencil_op)
{
    glEnable(GL_STENCIL_TEST);

    glStencilFunc(int(stencil_func), ref, read_mask);
    glStencilMask(write_mask);

    glStencilOp(GL_KEEP, GL_KEEP, int(stencil_op));//might be worth to expose sfail, dpfail 
}

void Shader::CullFunc()
{
    if (m_cull_func == ECullFuncs::CW)
    {   
        glEnable(GL_CULL_FACE);
        glFrontFace(GL_CW);
    }
    else if (m_cull_func == ECullFuncs::CCW)
    {
        glEnable(GL_CULL_FACE);
        glFrontFace(GL_CCW);
    }
    else//none
    {
        glDisable(GL_CULL_FACE);
    }
}

void Shader::BlendFunc(EBlendOps blend_func_src, EBlendOps blend_func_dst, EBlendOps blend_func_src_a, EBlendOps blend_fun_dst_a)
{
    glEnable(GL_BLEND);

    glBlendFuncSeparate(int(blend_func_src), int(blend_func_dst), int(blend_func_src_a), int(blend_fun_dst_a));
}

void Shader::CheckCompileErrors(unsigned int shader, std::string type)
{
    // utility function for checking shader compilation/linking errors.
    int success;
    char infoLog[1024];
    if (type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            //replace with deranos core log
            std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            //replace with deranos core log
            std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
}

void Shader::SetBool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(m_id, name.c_str()), (int)value);
}
void Shader::SetInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(m_id, name.c_str()), value);
}
void Shader::SetFloat(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(m_id, name.c_str()), value);
}
void Shader::SetFloat2(const std::string& name, float x, float y) const
{
	glUniform2f(glGetUniformLocation(m_id, name.c_str()), x, y);
}
void Shader::SetFloat3(const std::string& name, float x, float y, float z) const
{
	glUniform3f(glGetUniformLocation(m_id, name.c_str()), x, y, z);
}
void Shader::SetFloat4(const std::string& name, float x, float y, float z, float w) const
{
	glUniform4f(glGetUniformLocation(m_id, name.c_str()), x, y, z, w);
}

void Shader::SetMat2(const std::string& name, const glm::mat2& mat) const
{
    glUniformMatrix2fv(glGetUniformLocation(m_id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
void Shader::SetMat3(const std::string& name, const glm::mat3& mat) const
{
    glUniformMatrix3fv(glGetUniformLocation(m_id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
void Shader::SetMat4(const std::string& name, const glm::mat4& mat) const
{
    glUniformMatrix4fv(glGetUniformLocation(m_id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
