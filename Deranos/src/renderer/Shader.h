#pragma once
#include <Camera.h>
#include <Transform.h>
#include "Sampler.h"
#include <Texture.h>

enum class ECompareFuncs { ALWAYS = GL_ALWAYS, NEVER = GL_NEVER, LESS = GL_LESS, EQUAL = GL_EQUAL, 
	LEQUAL = GL_LEQUAL, GREATER = GL_GREATER, NOTEQUAL = GL_NOTEQUAL, GEQUAL = GL_GEQUAL};

enum class EStencilOps { KEEP = GL_KEEP, ZERO = GL_ZERO, REPLACE =  GL_REPLACE, INC = GL_INCR, INC_WRAP = GL_INCR_WRAP, 
	DEC = GL_DECR, DEC_WRAP = GL_DECR_WRAP, INVERT = GL_INVERT};

enum class EBlendOps { ZERO = GL_ZERO, ONE = GL_ONE, SRC_COLOR = GL_SRC_COLOR, ONE_MINUS_SRC_COLOR = GL_ONE_MINUS_SRC_COLOR, 
	DST_COLOR = GL_DST_COLOR, ONE_MINUS_DST_COLOR = GL_ONE_MINUS_DST_COLOR, SRC_ALPHA = GL_SRC_ALPHA, ONE_MINUS_SRC_ALPHA = GL_ONE_MINUS_SRC_ALPHA,
	DST_ALPHA = GL_DST_ALPHA, ONE_MINUS_DST_ALPHA = GL_ONE_MINUS_DST_ALPHA, };

class Shader
{
public:
	Shader(const char* vertexPath, const char* fragmentPath);

	void Bind(Texture& texture, Camera& camera, Transform& model_xform);
	void BindSampler(Texture& texture, const char* texture_name, int texture_slot);

	void DepthFunc(ECompareFuncs dpt_func, bool depth_write);
	void StencilFunc(ECompareFuncs stencil_func, int ref, int read_mask, int write_mask, EStencilOps stencil_op);
	void CullFunc();
	void BlendFunc(EBlendOps blend_func_src = EBlendOps::SRC_ALPHA, EBlendOps blend_func_dst = EBlendOps::ONE_MINUS_SRC_ALPHA, 
		EBlendOps blend_func_src_a = EBlendOps::ONE, EBlendOps blend_fun_dst_a = EBlendOps::ZERO);

	inline std::shared_ptr<Sampler> GetSampler() const { return m_sampler; };

	// utility uniform functions
	void SetBool(const std::string& name, bool value) const;
	void SetInt(const std::string& name, int value) const;
	void SetFloat(const std::string& name, float value) const;
	void SetFloat2(const std::string& name, float x, float y) const;
	void SetFloat3(const std::string& name, float x, float y, float z) const;
	void SetFloat4(const std::string& name, float x, float y, float z, float w) const;
	void SetMat2(const std::string& name, const glm::mat2& mat) const;
	void SetMat3(const std::string& name, const glm::mat3& mat) const;
	void SetMat4(const std::string& name, const glm::mat4& mat) const;
private:
	void CheckCompileErrors(unsigned int shader, std::string type);
	unsigned int m_id;
	std::shared_ptr<Sampler> m_sampler;

};

