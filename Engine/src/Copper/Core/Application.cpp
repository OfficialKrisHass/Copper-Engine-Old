//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#include "cupch.h"
#include "Application.h"

#include <GLFW/glfw3.h>

namespace Copper {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	std::vector<float> vertices = {

		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f

	};

	std::vector<uint32_t> indices = {

		0, 1, 2,
		2, 3, 0

	};

	void Application::Initialize() {

		//Here we initialize parts of the engine that need to be initializéd
		LogTrace("-------Application Initialization-------");

		renderer = Renderer::Create();

		Logger::Initialize();

		//Test if our Logging system functions correctly
		Log("you are too cute!");
		LogError("Variable 'No u' not defined");
		LogTrace("");

		window = std::unique_ptr<Window>(Window::Create());
		window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		//renderer->Initialize();

		shader = Shader::Create("assets/Shaders/vertexDefault.glsl", "assets/Shaders/fragmentDefault.glsl");
		renderer->SetShader(shader);

		vao = VertexArray::Create();
		vao->Bind();

		vbo = VertexBuffer::Create(vertices);
		ibo = IndexBuffer::Create(indices);

		vao->AddVertexBuffer(vbo);
		vao->AddIndexBuffer(ibo);

		vbo->Unbind();
		vao->Unbind();

		//Inform the User that the Application Initialization was successful
		Log("Application Succesfully Initialized!");
		LogTrace("----------------------------------------");

	}

	void Application::Run() {

		//This is the main Application Loop here we handle events, rendering input, everything that needs to be handled during runtime
		LogTrace("\n-------Application Game Loop-------");
		Log("Application Entered Game Loop");
		LogTrace("-----------------------------------");

		while (running) {

			renderer->ClearColor(0.18f, 0.18f, 0.18f);
			renderer->Render(vao);

			window->OnUpdate();

		}

	}

	void Application::OnEvent(Event& e) {

		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose), e);
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(OnWindowResize), e);

	}

	void Application::Shutdown() {

		//Here we Shutdown and clear everything left behind the application before successfully exiting the Application
		LogTrace("\n-------Application Shutdown-------");
		Log("Application Shutdown requested");
		LogTrace("----------------------------------");

	}

	bool Application::OnWindowClose(Event& e) {

		Log(e);
		running = false;

		return true;

	}

	bool Application::OnWindowResize(Event& e) {

		WindowResizeEvent event = *(WindowResizeEvent*)&e;

		renderer->SetViewport(0, 0, event.GetWidth(), event.GetHeight());

		return true;

	}

}