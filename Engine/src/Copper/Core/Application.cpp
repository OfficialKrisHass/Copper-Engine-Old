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

//A Define to Bind Functions to an event
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	//Create a null instance of this application
	Application* Application::instance = nullptr;

	//Vertex Data
	std::vector<float> vertices = {

		-0.5f, -0.5f,  0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,

		 0.5f, -0.5f,  0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f,  0.5f,

		-0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f, -0.5f,
		-0.5f,  0.5f, -0.5f,

	};

	//Vertex Indices
	std::vector<uint32_t> indices = {

		0, 1, 2,
		2, 3, 0,

		4, 5, 6,
		6, 7, 4,

		8, 9, 10,
		10, 11, 8,

	};
	
	//The Main Initialize Functions
	void Application::Initialize() {

		//Here we initialize parts of the engine that need to be initializéd
		LogTrace("-------Application Initialization-------");

		//Set the instance to this current instance
		instance = this;

		renderer = Renderer::Create();

		Logger::Initialize();

		//Test if our Logging system functions correctly
		Log("you are too cute!");
		LogError("Variable 'No u' not defined");
		LogTrace("");

		//Create our new Window and set the Event Callback to the OnEvent Function
		window = std::unique_ptr<Window>(Window::Create());
		window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		//renderer->Initialize();

		//Create and Set our Rendering Shader
		shader = Shader::Create("assets/Shaders/vertexDefault.glsl", "assets/Shaders/fragmentDefault.glsl");
		renderer->SetShader(shader);

		//Create our VAO, VBO, IBO and set them how we need
		vao = VertexArray::Create();
		vao->Bind();

		vbo = VertexBuffer::Create(vertices);
		ibo = IndexBuffer::Create(indices);

		vao->AddVertexBuffer(vbo);
		vao->AddIndexBuffer(ibo);

		vbo->Unbind();
		vao->Unbind();

		//Create a Model
		Shared<Transform> transform = std::shared_ptr<Transform>(new Transform(glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f), glm::vec3(1.0f)));
		Shared<Transform> camTransform = std::shared_ptr<Transform>(new Transform(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f), glm::vec3(1.0f)));

		mesh = std::shared_ptr<Mesh>(new Mesh(transform, vao));
		cam = std::shared_ptr<Camera>(new Camera(camTransform));

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

			//Render the background
			renderer->ClearColor(0.18f, 0.18f, 0.18f);

			//Render the VAO
			renderer->Render(mesh, cam);

			//Update Window
			window->OnUpdate();

		}

	}

	//Main OnEvent function that handles Event from the entire Application
	void Application::OnEvent(Event& e) {

		//Dispatch the WindowClose and Window Events
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose), e);
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(OnWindowResize), e);

	}

	//The Main Shutdown Application to shutdown and clean the Application
	void Application::Shutdown() {

		//Here we Shutdown and clear everything left behind the application before successfully exiting the Application
		LogTrace("\n-------Application Shutdown-------");
		Log("Application Shutdown requested");
		LogTrace("");

		vao.reset();
		vbo.reset();
		ibo.reset();
		shader.reset();

		window.reset();

		LogTrace("----------------------------------");

	}

	//WindowClose Event
	bool Application::OnWindowClose(Event& e) {

		//Stop the Application
		running = false;

		return true;

	}

	//WindowResize Event
	bool Application::OnWindowResize(Event& e) {

		//Get the WIndowResizeEvent so that we can get the data from it
		WindowResizeEvent event = *(WindowResizeEvent*)&e;

		//Set the Rendering Viewport
		renderer->SetViewport(0, 0, event.GetWidth(), event.GetHeight());

		return true;

	}

}