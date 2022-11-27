#include "pch.h"
#include "Renderer.h"
#include "Gui.h"
#include "Button.h"
#include "RenderTarget.h"
#include "RendererDebuger.h"

Renderer::Renderer(Window& window, Timer& timer)
	: m_window(window), m_timer(timer), m_show_wireframe(false)
{
	m_gui = std::make_shared<Gui>(m_window);

	m_camera = std::make_shared<Camera>(m_window);

	m_scene = std::make_shared<Scene>(*m_camera);

	InitializeGlad();

	RendererDebuger::Init();

	DERANOS_CORE_INFO("Renderer::INITIALIZED");
}

void Renderer::InitializeGlad()//#To do: hide under abstraction
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		DERANOS_CORE_ERROR("Failed to Initialize GLAD!");
	}
}

void Renderer::ClearZbuffer()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_DEPTH_BUFFER_BIT);
}

void Renderer::ClearStencil()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_STENCIL_BUFFER_BIT);
}

void Renderer::SetPolyFillMode()
{
	if (m_show_wireframe)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);//wireframe
	}
	else
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);//regular filled polygons
	}
}

void Renderer::PreRender()
{
	//#To do dont load the cube mesh over & over again
	//#To do Entity class since model class is to explicit?(lights, etc)?

	//Skybox
	std::shared_ptr<Model> skybox = std::make_shared<Model>("resources/models/cube/cube.obj");
	std::shared_ptr<Shader> skybox_shader = std::make_shared<Shader>("shaders/skybox.vs", "shaders/skybox.ps");
	std::shared_ptr<Texture> sky_cubemap = std::make_shared<Texture>("resources/textures/skyboxes/day_", TextureTypes::Cubemap());
	skybox->material->shader = skybox_shader;
	skybox->material->shader->SetCullFunc(ECullFuncs::CW);
	skybox->material->texture = sky_cubemap;
	skybox->model_xform->scale = glm::vec3(9999.0, 9999.0, 9990.0f);
	m_scene->models.push_back(skybox);

	//Ground
	std::shared_ptr<Model> m_ground = std::make_shared<Model>("resources/models/cube/cube.obj");
	m_ground->model_xform->position = glm::vec3(0.0, -25.0, 0.0f);
	m_ground->model_xform->scale = glm::vec3(1500.0, 4.0, 1500.0f);
	m_scene->models.push_back(m_ground);

	//Cube
	m_cube = std::make_shared<Model>("resources/models/cube/cube.obj");
	m_cube->model_xform->position += glm::vec3(4.3, 4.0, -16.050f);
	m_cube->model_xform->scale = glm::vec3(3.0, 3.0, 3.0f);
	m_scene->models.push_back(m_cube);

	//Backpack
	std::shared_ptr<Texture> backpack_diffuse = std::make_shared<Texture>("resources/models/backpack/diffuse.jpg", TextureTypes::Diffuse());
	m_backpack = std::make_shared<Model>("resources/models/backpack/backpack.obj");
	m_backpack->material->texture = backpack_diffuse;
	m_backpack->model_xform->position += glm::vec3(-1.0, 0.0, -5.0f);
	m_scene->models.push_back(m_backpack);

	//Copy Material
	std::shared_ptr<Shader> copy_shader = std::make_shared<Shader>("shaders/copy.vs", "shaders/copy.ps");
	copy_shader->SetCullFunc(ECullFuncs::NONE);
	m_copy_material = std::make_shared<Material>();
	m_copy_material->shader = copy_shader;

	//Quad
	m_quad = std::make_shared<Mesh>();	
}

void Renderer::DrawGui()
{
	m_gui->Init();

	ImGui::Begin("Editor");
	ImGui::SetWindowFontScale(1.5f);
	ImGui::Text("FPS: ");
	ImGui::Text(std::to_string(m_timer.GetFPS()).c_str());//awful conversion to be corrected
	ImGui::Separator();
	ImGui::Text("Camera");
	Button::Drag("Position", m_camera->position_ws);
	Button::Drag("Rotation", m_camera->orientation);
	Button::Slider("Field of View", m_camera->fov, 1.0f, 180.0f);
	Button::Slider("Near Clipping Plane", m_camera->near_clipping_plane, 0.01f, 500.0f);
	Button::Slider("Far Clipping Plane", m_camera->far_clipping_plane, 0.0f, 99999.9f);
	ImGui::Separator();

	ImGui::Text("Backpack");
	Button::Drag("Position ", m_backpack->model_xform->position);
	Button::Drag("Scale", m_backpack->model_xform->scale);
	ImGui::Separator();

	ImGui::Text("Cube");
	Button::Drag("Position  ", m_cube->model_xform->position);
	Button::Drag("Scale ", m_cube->model_xform->scale);
	ImGui::Separator();

	ImGui::Text("Post Processing");
	float sharpen = 0.0f;
	Button::Slider("Sharpen", sharpen, 0.0f, 1.0f);
	ImGui::Separator();

	ImGui::Text("Settings");
	Button::Checkbox("Show Wireframe", m_show_wireframe);
	ImGui::End();

	m_gui->Render();
}

void Renderer::CopyToBackBuffer(std::shared_ptr<Texture> texture)
{
	m_copy_material->texture = texture;
	m_copy_material->Bind();

	BackBuffer::SetRenderTargetView();
	m_quad->Draw();
}

void Renderer::Renderloop()
{
	SetPolyFillMode();//should be event callback based to not check if over & over again

	BackBuffer::Clear(glm::vec4(0.0, 0.0, 1.0, 1.0));
	ClearZbuffer();
	ClearStencil();

	BackBuffer::SetRenderTargetView();
	
	m_scene->Draw();
	

	//CopyToBackBuffer(xd);
	//Texture* gbuffer_diffuse = new Texture(GL_TEXTURE_2D, GL_RGB8, GL_RGB, m_window.GetWidth(), m_window.GetHeight());
	//delete gbuffer_diffuse;

	DrawGui();
}

void Renderer::Present()
{	
	glfwSwapBuffers(m_window.GetWindow());
} 

void Renderer::OnInput()
{
	m_camera->OnInput();
}