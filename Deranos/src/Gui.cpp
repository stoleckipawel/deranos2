#include "pch.h"
#include "Gui.h"

void Gui::SetStyle()
{
	ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 4.0f);
}

Gui::Gui(std::shared_ptr<Window>& window)
	: m_window(window)
{
	//IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(m_window->GetWindow(), true);
	ImGui_ImplOpenGL3_Init("#version 330");
	Gui::SetStyle();
}

Gui::~Gui()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void Gui::Init()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void Gui::Render()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
