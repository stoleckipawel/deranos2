#pragma once
#include <Window.h>

class Gui
{
public:
	Gui(std::shared_ptr<Window>& window);
	~Gui();
	void Gui::Init();
	void Gui::Render();
	void Gui::Checkbox(const char* name, bool& value);
	void Gui::Slider(const char* name, float& value, float min, float max);
	void Gui::Color(const char* name, float value[4]);
private:
	std::shared_ptr<Window>& m_window;
};

