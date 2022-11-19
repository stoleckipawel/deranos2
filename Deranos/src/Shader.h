#pragma once
#include <Camera.h>
#include <Transform.h>
#include "Sampler.h"
#include <Texture.h>

class Shader
{
public:
	Shader(const char* vertexPath, const char* fragmentPath);

	void Bind(Texture& texture, Camera& camera, Transform& model_xform);
	void BindSampler(Texture& texture, const char* texture_name, int texture_slot);
	void DepthFunc();
	void CullFunc();
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

