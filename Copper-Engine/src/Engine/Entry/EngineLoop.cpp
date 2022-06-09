#include "cupch.h"
#include "EngineLoop.h"

#include "Engine/Events/ApplicationEvent.h"
#include "Engine/Events/KeyEvent.h"
#include "Engine/Events/MouseEvent.h"

#include "Engine/Renderer/Renderer.h"

#include <GLAD/glad.h>
#include <glm/glm.hpp>

namespace Copper {

	EngineLoop* EngineLoop::instance = nullptr;

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

	void EngineLoop::Init() {

		instance = this;

		LoggerInit();
		Header("-------EngineLoop Initialization started------");

		window = Window::Create({ 1280, 720, "Copper Engine" });
		window->SetEventCallback(BindFunction(EngineLoop::OnEvent));

		Renderer::Initialize();

		shader = Shader::Create("assets/Shaders/vertexDefault.glsl", "assets/Shaders/fragmentDefault.glsl");
		Renderer::SetShader(shader);

		vao = VertexArray::Create();

		vbo = VertexBuffer::Create(vertices);
		ibo = IndexBuffer::Create(indices);

		vao->AddVertexBuffer(vbo);
		vao->AddIndexBuffer(ibo);

		vbo->Unbind();
		vao->Unbind();

		transform = Transform(Vector3(0.0f), Vector3(0.0f), Vector3(1.0f));
		camera = Camera(Vector3(0.0f, 0.0f, 1.0f), Vector3(0.0f), 90.0f);

		Empty();
		Header("-----Engine Initialization was Successful-----");

	}

	void EngineLoop::Run() {

		Header("-----EngineLoop entered the program Loop!-----");

		while (running) {

			Renderer::ClearColor(0.18f, 0.18f, 0.18f);
			Renderer::Render(vao, transform, camera);

			window->Update();

		}

		Empty();
		Header("-------Engine has Left the Program Loop-------");

	}

	void EngineLoop::Shutdown() {

		Header("---------EngineLoop is shutting down----------");

		window->Shutdown();

	}

	void EngineLoop::OnEvent(Event& e) {

		dispatcher.Dispatch<WindowResizeEvent>(BindFunction(EngineLoop::OnWindowResize), e);
		dispatcher.Dispatch<WindowCloseEvent>(BindFunction(EngineLoop::OnWindowClose), e);

	}
	
	bool EngineLoop::OnWindowClose(Event& e) {

		running = false;

		return true;

	}

	bool EngineLoop::OnWindowResize(Event& e) {

		WindowResizeEvent event = *(WindowResizeEvent*) &e;

		Renderer::SetViewport(event.GetWidth(), event.GetHeight());

		return true;

	}

}