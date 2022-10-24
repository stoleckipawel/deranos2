#pragma once

class Shader
{
public:
	unsigned int ID;

	// constructor reads and builds the shader
	Shader(const char* vertexPath, const char* fragmentPath);

	void Bind();

	// utility uniform functions
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setFloat2(const std::string& name, float x, float y) const;
	void setFloat3(const std::string& name, float x, float y, float z) const;
	void setFloat4(const std::string& name, float x, float y, float z, float w) const;
	void Shader::setMat2(const std::string& name, const glm::mat2& mat) const;
	void Shader::setMat3(const std::string& name, const glm::mat3& mat) const;
	void Shader::setMat4(const std::string& name, const glm::mat4& mat) const;
private:
	void checkCompileErrors(unsigned int shader, std::string type);
};

