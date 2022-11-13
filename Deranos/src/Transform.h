#pragma once
class Transform
{
public:
	Transform();

	glm::mat4 GetMatrix();

	glm::vec3 scale;
	glm::vec3 position;
	glm::vec3 rotation;
private:

};

