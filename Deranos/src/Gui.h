#pragma once
#include <Window.h>

class Gui
{
public:
	Gui(std::shared_ptr<Window>& window);
	~Gui();
	void Init();
	void Render();
	void Checkbox(const char* name, bool& value);
	void Slider(const char* name, float& value, float min, float max);
	void Slider(const char* name, float value[3], float min, float max);
	void Drag(const char* name, float value[3], float speed = 0.01);
	void Color(const char* name, float value[4]);
private:
	std::shared_ptr<Window>& m_window;
};

