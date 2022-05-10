//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#include "cupch.h"
#include "Application.h"

#include <GLFW/glfw3.h>
#include <ImGui/imgui.h>

namespace Copper {

	//Create a null instance of this application
	Application* Application::instance = nullptr;

	//Vertex Data
	std::vector<float> vertices = {

		//Front Face
		-0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 1.0f,	0.0f, 0.0f, //0
		 0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 1.0f,	1.0f, 0.0f, //1
		 0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 1.0f,	1.0f, 1.0f, //2
		-0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 1.0f,	0.0f, 1.0f, //3

		//Back Face
		 0.5f, -0.5f, -0.5f,	1.0f, 1.0f, 0.0f,	0.0f, 0.0f, //4
		-0.5f, -0.5f, -0.5f,	1.0f, 1.0f, 0.0f,	1.0f, 0.0f, //5
		-0.5f,  0.5f, -0.5f,	1.0f, 1.0f, 0.0f,	1.0f, 1.0f, //6
		 0.5f,  0.5f, -0.5f,	1.0f, 1.0f, 0.0f,	0.0f, 1.0f, //7

		//Left Face
		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f, 1.0f,	0.0f, 0.0f, //8
		-0.5f, -0.5f,  0.5f,	0.0f, 1.0f, 1.0f,	1.0f, 0.0f, //9
		-0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 1.0f,	1.0f, 1.0f, //10
		-0.5f,  0.5f, -0.5f,	0.0f, 1.0f, 1.0f,	0.0f, 1.0f, //11

		//Right Face
		 0.5f, -0.5f,  0.5f,	1.0f, 0.0f, 0.0f,	0.0f, 0.0f, //12
		 0.5f, -0.5f, -0.5f,	1.0f, 0.0f, 0.0f,	1.0f, 0.0f, //13
		 0.5f,  0.5f, -0.5f,	1.0f, 0.0f, 0.0f,	1.0f, 1.0f, //14
		 0.5f,  0.5f,  0.5f,	1.0f, 0.0f, 0.0f,	0.0f, 1.0f, //15

		//Up Face
		-0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f, //16
		 0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	1.0f, 0.0f, //17
		 0.5f,  0.5f, -0.5f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f, //18
		-0.5f,  0.5f, -0.5f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f, //19

		//Down Face
		-0.5f, -0.5f, -0.5f,	1.0f, 0.0f, 1.0f,	0.0f, 0.0f, //20
		 0.5f, -0.5f, -0.5f,	1.0f, 0.0f, 1.0f,	1.0f, 0.0f, //21
		 0.5f, -0.5f,  0.5f,	1.0f, 0.0f, 1.0f,	1.0f, 1.0f, //22
		-0.5f, -0.5f,  0.5f,	1.0f, 0.0f, 1.0f,	0.0f, 1.0f, //23

	};

	//Vertex Indices
	std::vector<uint32_t> indices = {

		0, 1, 2,
		2, 3, 0,

		4, 5, 6,
		6, 7, 4,

		8, 9, 10,
		10, 11, 8,

		12, 13, 14,
		14, 15, 12,

		16, 17, 18,
		18, 19, 16,

		20, 21, 22,
		22, 23, 20

	};
	
	int size = 10;

	//The Main Initialize Functions
	void Application::Initialize() {

		//Here we initialize parts of the engine that need to be initializ�d
		EngineLogTrace("-------Application Initialization-------");

		//Set the instance to this current instance
		instance = this;

		renderer = Renderer::Create();

		Logger::Initialize();

		//Test if our Logging system functions correctly
		EngineLog("you are too cute!");
		EngineLogError("Variable 'No u' not defined");
		EngineLogTrace("");

		//Create our new Window and set the Event Callback to the OnEvent Function
		window = std::unique_ptr<Window>(Window::Create());
		window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

		imGuiLayer = new ImGuiLayer();
		PushOverlay(imGuiLayer);

		renderer->Initialize();

		//Create and Set our Rendering Shader
		shader = Shader::Create("assets/Shaders/vertexDefault.glsl", "assets/Shaders/fragmentDefault.glsl");
		renderer->SetShader(shader);

		//Create our VAO, VBO, IBO and set them how we need
		vao = VertexArray::Create();
		vao->Bind();

		vbo = VertexBuffer::Create(vertices);
		ibo = IndexBuffer::Create(indices);

		BufferLayout layout = {

			{"position", DataType::Float3},
			{"color", DataType::Float3},
			{"uvs", DataType::Float2}

		};

		vbo->SetLayout(layout);

		vao->AddVertexBuffer(vbo);
		vao->AddIndexBuffer(ibo);

		vbo->Unbind();
		vao->Unbind();

		texture = Texture::Create("assets/Textures/pfp.png");

		//Create a Model
		Shared<Transform> transform = std::shared_ptr<Transform>(new Transform(glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f), glm::vec3(1.0f)));
		Shared<Transform> camTransform = std::shared_ptr<Transform>(new Transform(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f), glm::vec3(1.0f)));

		mesh = std::shared_ptr<Mesh>(new Mesh(transform, vao, texture));
		cam = std::shared_ptr<Camera>(new Camera(camTransform));

		shader->Bind();
		shader->SetInt(0, "tex0");
		shader->Unbind();

		//Inform the User that the Application Initialization was successful
		EngineLog("Application Succesfully Initialized!");
		EngineLogTrace("----------------------------------------");

#ifdef CU_EDITOR

		//Editor
		editor = CreateUnique<Editor::Editor>();

		editor->OnStart();

#endif

	}

	void Application::Run() {

		//This is the main Application Loop here we handle events, rendering input, everything that needs to be handled during runtime
		EngineLogTrace("\n-------Application Game Loop-------");
		EngineLog("Application Entered Game Loop");
		EngineLogTrace("-----------------------------------");

		while (running) {

			//Render the background
			renderer->ClearColor(0.18f, 0.18f, 0.18f);

			//Render the VAO
			renderer->Render(mesh, cam);

			for (Layer* layer : layerStack) {

				layer->OnUpdate();

			}

			imGuiLayer->Begin();

			for (Layer* layer : layerStack) {

				layer->OnImGuiRender();

			}

			imGuiLayer->End();

#ifdef CU_EDITOR

			//Update Editor
			editor->OnUpdate();

#endif

			//Update Window
			window->OnUpdate();

		}

	}

	//Main OnEvent function that handles Event from the entire Application
	void Application::OnEvent(Event& e) {

		//Dispatch the WindowClose and Window Events
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose), e);
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(Application::OnWindowResize), e);

		for (auto it = layerStack.end(); it != layerStack.begin(); ) {

			(*--it)->OnEvent(e);

			if (e.handled) { break; }

		}

		if (!e.handled) {

			editor->OnEvent(e);

		}

	}

	//The Main Shutdown Application to shutdown and clean the Application
	void Application::Shutdown() {

		//Here we Shutdown and clear everything left behind the application before successfully exiting the Application
		EngineLogTrace("\n-------Application Shutdown-------");
		EngineLog("Application Shutdown requested");
		EngineLogTrace("");

		vao.reset();
		vbo.reset();
		ibo.reset();
		shader.reset();

		window.reset();

#ifdef CU_EDITOR

		editor->OnExit();

#endif

		EngineLogTrace("----------------------------------");

	}

	//WindowClose Event
	bool Application::OnWindowClose(Event& e) {

		//Stop the Application
		running = false;

		EngineLog(e);

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