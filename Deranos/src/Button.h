#pragma once
static class Button
{
public:
	static void Checkbox(const char* name, bool& value);
	static void Slider(const char* name, float& value, float min, float max);
	static void Slider(const char* name, float value[3], float min, float max);
	static void Drag(const char* name, float value[3], float speed = 0.01);
	static void Drag(const char* name, glm::vec3& value, float speed = 0.01);
	static void Color(const char* name, float value[4]);
};

