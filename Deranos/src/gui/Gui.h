#pragma once
#include <Window.h>

class Gui
{
public:
	Gui(Window& window);
	~Gui();
	void Init();
	void SetStyle();
	void Render();
private:
	Window& m_window;
};

