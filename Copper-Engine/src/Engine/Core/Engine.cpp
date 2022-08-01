#include "cupch.h"
#include "Engine.h"

#include "Engine/Core/Window.h"

#include "Engine/Events/Event.h"
#include "Engine/Events/ApplicationEvent.h"
#include "Engine/Events/KeyEvent.h"
#include "Engine/Events/MouseEvent.h"

#include "Engine/Renderer/Renderer.h"
#include "Engine/Renderer/Shader.h"

#include "Engine/Scene/Components/Transform.h"
#include "Engine/Scene/Components/Camera.h"
#include "Engine/Scene/Components/Mesh.h"

#include "Engine/Scene/Scene.h"
#include "Engine/Scene/Object.h"

#include "Engine/UI/ImGui.h"

#include "Editor/Core/Editor.h"

namespace Copper {

	struct EngineData {

		bool running = true;

		EventDispatcher dispatcher;

		Unique<Window> window;
		Shared<Shader> shader;

		Editor::Editor editor;

	};

	static EngineData data;

	void OnEvent(Event& e);

	bool OnWindowResize(Event& e);
	bool OnWindowClose(Event& e);

	void InitializeEngine() {

		LoggerInit();
		Header("-------EngineLoop Initialization started------");

		data.window = Window::Create({ 1280, 720, "Copper Engine" });
		data.window->SetEventCallback(std::bind(&OnEvent, std::placeholders::_1));

		UI::Initialize();
		data.editor.Initialize();
		Renderer::Initialize();

		data.shader = Shader::Create("assets/Shaders/vertexDefault.glsl", "assets/Shaders/fragmentDefault.glsl");
		Renderer::SetShader(data.shader);


		Empty();
		Header("-----Engine Initialization was Successful-----");

	}

	void RunEngine() {

		Header("-----EngineLoop entered the program Loop!-----");

		while (data.running) {

			data.editor.Update();

			UI::Begin();
			data.editor.UIUpdate();
			UI::End();

			data.window->Update();

		}

		Empty();
		Header("-------Engine has Left the Program Loop-------");

	}

	void ExitEngine() {

		Header("---------EngineLoop is shutting down----------");

		data.window->Shutdown();

		UI::Shutdown();
		data.editor.Shutdown();

	}

	//------------------
	//------Events------
	//------------------
	void OnEvent(Event& e) {

		data.dispatcher.Dispatch<WindowResizeEvent>(std::bind(&OnWindowResize, std::placeholders::_1), e);
		data.dispatcher.Dispatch<WindowCloseEvent>(std::bind(&OnWindowClose, std::placeholders::_1), e);

	}

	bool OnWindowResize(Event& e) {

		WindowResizeEvent event = *(WindowResizeEvent*) &e;

		Renderer::SetViewport(event.GetWidth(), event.GetHeight());

		return true;

	}

	bool OnWindowClose(Event& e) {

		data.running = false;

		return true;

	}

	//-------------------
	//------Getters------
	//-------------------
	Window& GetWindow() { return *data.window; }

}