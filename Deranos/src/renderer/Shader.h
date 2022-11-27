#pragma once
#include <Camera.h>
#include <Transform.h>
#include <Texture.h>

enum class EWrapMode {
	Default = GL_CLAMP_TO_EDGE,
	Wrap = GL_REPEAT,
	Clamp = GL_CLAMP_TO_EDGE,
	Mirror = GL_MIRRORED_REPEAT
};

enum class EFilteringMode {
	Default = GL_NEAREST,
	Point = GL_NEAREST,
	Linear = GL_LINEAR,
	LinearMipLinear = GL_LINEAR_MIPMAP_LINEAR,
	PointMipLinear = GL_NEAREST_MIPMAP_LINEAR,
	LinearMipPoint = GL_LINEAR_MIPMAP_NEAREST,
	PointMipPoint = GL_NEAREST_MIPMAP_LINEAR
};

enum class EMaxAnisotropyLevel {
	Default = 1,
	None = 1,
	Low = 4,
	Medium = 8,
	High = 16
};

enum class ECompareFuncs {
	ALWAYS = GL_ALWAYS, NEVER = GL_NEVER, LESS = GL_LESS, EQUAL = GL_EQUAL,
	LEQUAL = GL_LEQUAL, GREATER = GL_GREATER, NOTEQUAL = GL_NOTEQUAL, GEQUAL = GL_GEQUAL
};

enum class EStencilOps {
	KEEP = GL_KEEP, ZERO = GL_ZERO, REPLACE = GL_REPLACE, INC = GL_INCR, INC_WRAP = GL_INCR_WRAP,
	DEC = GL_DECR, DEC_WRAP = GL_DECR_WRAP, INVERT = GL_INVERT
};

enum class EBlendOps {
	ZERO = GL_ZERO, ONE = GL_ONE, SRC_COLOR = GL_SRC_COLOR, ONE_MINUS_SRC_COLOR = GL_ONE_MINUS_SRC_COLOR,
	DST_COLOR = GL_DST_COLOR, ONE_MINUS_DST_COLOR = GL_ONE_MINUS_DST_COLOR, SRC_ALPHA = GL_SRC_ALPHA, ONE_MINUS_SRC_ALPHA = GL_ONE_MINUS_SRC_ALPHA,
	DST_ALPHA = GL_DST_ALPHA, ONE_MINUS_DST_ALPHA = GL_ONE_MINUS_DST_ALPHA,
};

enum class ECullFuncs { CW, CCW, NONE };

class Sampler
{
public:
	Sampler(Texture& texture, int texture_slot, EWrapMode wrap_mode = EWrapMode::Default, EFilteringMode filtering = EFilteringMode::Default, EMaxAnisotropyLevel max_anisotropy_level = EMaxAnisotropyLevel::Default);
	void Bind();
	void Bind(Texture& texture, int texture_slot, EWrapMode wrap_mode, EFilteringMode filtering, EMaxAnisotropyLevel max_anisotropy_level);
	void SetWrapMode(EWrapMode wrap_mode);
	void SetFiltering(EFilteringMode filtering, EMaxAnisotropyLevel max_anisotropy_level);
	void SetMaxAnisotropyLevel(EMaxAnisotropyLevel max_anisotropy_level);
private:
	Texture& m_texture;
	int m_texture_slot;
	EWrapMode m_wrap_mode;
	EFilteringMode m_filtering;
	EMaxAnisotropyLevel m_max_anisotropy_level;
};

class Shader
{
public:
	Shader(const char* vertexPath, const char* fragmentPath);
	
	void Bind(Texture& texture);
	void Bind(Texture& texture, Camera& camera, Transform& model_xform);
	void BindSampler(Texture& texture, const char* texture_name, int texture_slot);

	void SetCullFunc(ECullFuncs cull_func);
	void SetDepthFunc(ECompareFuncs depth_func, bool write_depth);

	void SetBool(const std::string& name, bool value) const;
	void SetInt(const std::string& name, int value) const;
	void SetFloat(const std::string& name, float value) const;
	void SetFloat2(const std::string& name, float x, float y) const;
	void SetFloat3(const std::string& name, float x, float y, float z) const;
	void SetFloat4(const std::string& name, float x, float y, float z, float w) const;
	void SetMat2(const std::string& name, const glm::mat2& mat) const;
	void SetMat3(const std::string& name, const glm::mat3& mat) const;
	void SetMat4(const std::string& name, const glm::mat4& mat) const;

	inline std::shared_ptr<Sampler> GetSampler() const { return m_sampler; };
private:
	void Compile(const char* vertexPath, const char* fragmentPath);
	void CheckCompileErrors(unsigned int shader, std::string type);

	void CullFunc();
	void DepthFunc();
	void StencilFunc(ECompareFuncs stencil_func, int ref, int read_mask, int write_mask, EStencilOps stencil_op);
	void BlendFunc(EBlendOps blend_func_src = EBlendOps::SRC_ALPHA, EBlendOps blend_func_dst = EBlendOps::ONE_MINUS_SRC_ALPHA,
		EBlendOps blend_func_src_a = EBlendOps::ONE, EBlendOps blend_fun_dst_a = EBlendOps::ZERO);
	void SetMatrixes(Camera& camera, Transform& model_xform);

	unsigned int m_id;
	std::shared_ptr<Sampler> m_sampler;

	ECompareFuncs m_depth_func;//Should be read from the shader in the future
	bool m_write_depth;//Should be read from the shader in the future
	ECullFuncs m_cull_func;//Should be read from the shader in the future
};




