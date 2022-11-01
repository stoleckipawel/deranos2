#pragma once
#include <Window.h>

class Gui
{
public:
	Gui(std::shared_ptr<Window>& window);
	~Gui();
	void Init();
	void SetStyle();
	void Render();
private:
	std::shared_ptr<Window>& m_window;
};

