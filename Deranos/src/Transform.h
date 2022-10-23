#pragma once
class Transform
{
public:
	void SetScale(float scale);
	void SetScale(float x, float y, float z);
	glm::vec3 GetScale();
	void Translate(float x, float y, float z);
	void Translate(glm::vec3 xyz);
	void SetPosition(float x, float y, float z);
	glm::vec3 GetPosition();
	void SetRotation(float x, float y, float z);
	glm::vec3 GetRotation();
	void Rotate(float x, float y, float z);

	glm::mat4 GetMatrix();
private:
	glm::vec3 m_scale = glm::vec3(1.0f, 1.0f, 1.0f);
	glm::vec3 m_position = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 m_rotation = glm::vec3(1.0f, 1.0f, 1.0f);
};

