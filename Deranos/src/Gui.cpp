#include "pch.h"
#include "Gui.h"

Gui::Gui(std::shared_ptr<Window>& window)
	: m_window(window)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(m_window->GetWindow(), true);
	ImGui_ImplOpenGL3_Init("#version 330");
}

Gui::~Gui()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void Gui::Checkbox(const char* name, bool& value)
{
	ImGui::Checkbox(name, &value);
}

void Gui::Slider(const char* name, float& value, float min, float max)
{
	ImGui::SliderFloat(name, &value, min, max);
}

void Gui::Color(const char* name, float value[4])
{
	ImGui::ColorEdit4(name, value);
}

void Gui::Init()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
	ImGui::Begin("Wannabe Editor");
}

void Gui::Render()
{
	ImGui::End();
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
