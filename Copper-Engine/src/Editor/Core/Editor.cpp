#include "cupch.h"
#include "Editor.h"

#include "Engine/Renderer/Renderer.h"

#include "Engine/Scene/Components/Transform.h"
#include "Engine/Scene/Components/Camera.h"
#include "Engine/Scene/Components/Mesh.h"

#include <ImGui/imgui.h>

using namespace Copper;

namespace Editor {
	
	std::vector<float> vertices{

		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f,

	};

	std::vector<uint32_t> indices{

		0, 1, 2,
		2, 3, 0

	};

	void Editor::Initialize() {

		viewportSize = UVector2(1280, 720);
		sceneHierarchy = SceneHierarchy();
		properties = Properties();

		fbo = Copper::FrameBuffer::Create(UVector2(1280, 720));

		//Scene
		scene = Scene();
		square = scene.CreateObject("Square");
		camera = scene.CreateObject("Camera");

		//Square
		square.transform->position.z -= 1.0f;
		Mesh* m = square.AddComponent<Mesh>();

		m->vertices = vertices;
		m->indices = indices;
		m->UpdateMesh();

		//Camera
		Camera* c = camera.AddComponent<Camera>();

		sceneHierarchy.SetScene(&scene);

	}

	void Editor::Update() {

		if (fbo->Width() != viewportSize.x || fbo->Height() != viewportSize.y) {

			fbo->Resize(viewportSize);
			camera.GetComponent<Camera>()->Resize(viewportSize);

		}

		camera.GetComponent<Camera>()->Move();

		fbo->Bind();
		scene.Update();
		fbo->Unbdind();

		properties.SetSelectedObject(sceneHierarchy.GetSelectedObject());

	}

	void Editor::UIUpdate() {

		RenderDockspace();

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2{ 0, 0 });
		ImGui::Begin("Viewport");

		ImVec2 windowSize = ImGui::GetContentRegionAvail();
		viewportSize = UVector2(windowSize.x, windowSize.y);

		uint64_t texture = fbo->GetColorAttachment();
		ImGui::Image(reinterpret_cast<void*>(texture), windowSize, ImVec2{ 0, 1 }, ImVec2{ 1, 0 });
		ImGui::End();
		ImGui::PopStyleVar();

		sceneHierarchy.Render();
		properties.Render();

		ImGui::End(); //Dockspace

	}

	void Editor::RenderDockspace() {

		static bool dockspaceOpen = true;
		static bool opt_fullscreen_persistant = true;
		bool opt_fullscreen = opt_fullscreen_persistant;
		static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

		ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;

		if (opt_fullscreen) {

			ImGuiViewport* viewport = ImGui::GetMainViewport();

			ImGui::SetNextWindowPos(viewport->Pos);
			ImGui::SetNextWindowSize(viewport->Size);
			ImGui::SetNextWindowViewport(viewport->ID);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);

			window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
			window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

		}

		if (dockspace_flags & ImGuiDockNodeFlags_PassthruDockspace) window_flags |= ImGuiWindowFlags_NoBackground;

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
		ImGui::Begin("DockSpace Demo", &dockspaceOpen, window_flags); //Dockspace
		ImGui::PopStyleVar();

		if (opt_fullscreen) ImGui::PopStyleVar(2);

		ImGuiIO& io = ImGui::GetIO();
		ImGuiStyle& style = ImGui::GetStyle();

		float minWinSizeX = style.WindowMinSize.x;
		style.WindowMinSize.x = 370.0f;

		if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable) {

			ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");

			ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);

		}

		style.WindowMinSize.x = minWinSizeX;

	}

	void Editor::Shutdown() {

		//

	}

}