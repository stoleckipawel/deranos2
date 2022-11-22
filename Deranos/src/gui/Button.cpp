#include "pch.h"
#include "Button.h"


void Button::Checkbox(const char* name, bool& value)
{
	ImGui::Checkbox(name, &value);
}

void Button::Slider(const char* name, float& value, float min, float max)
{
	ImGui::SliderFloat(name, &value, min, max);
}

void Button::Slider(const char* name, float value[3], float min, float max)
{
	ImGui::SliderFloat3(name, value, min, max);
}

void Button::Drag(const char* name, float value[3], float speed)
{
	ImGui::DragFloat3(name, value, speed);
}

void Button::Drag(const char* name, glm::vec2& value, float speed)
{
	float value2[2] = {value.x, value.y};
	ImGui::DragFloat2(name, value2, speed);
	value = glm::vec2(value2[0], value2[1]);
}

void Button::Drag(const char* name, glm::vec3& value, float speed)
{
	float value3[3] = { value.x, value.y, value.z };
	ImGui::DragFloat3(name, value3, speed);
	value = glm::vec3(value3[0], value3[1], value3[2]);
}

void Button::Color(const char* name, float value[4])
{
	ImGui::ColorEdit4(name, value);
}