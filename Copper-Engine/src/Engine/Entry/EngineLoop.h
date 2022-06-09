#pragma once

#include "Engine/Core/Core.h"
#include "Engine/Core/Window.h"

#include "Engine/Events/Event.h"

#include "Engine/Renderer/Buffer.h"
#include "Engine/Renderer/VertexArray.h"
#include "Engine/Renderer/Shader.h"

#include "Engine/Scene/Transform.h"
#include "Engine/Scene/Camera.h"

namespace Copper {

	class EngineLoop {

	public:
		//EngineLoop() {}

		void Init();
		void Run();
		void Shutdown();

		void OnEvent(Event& e);

		inline static EngineLoop& Get() { return *instance; }
		inline Window& GetWindow() { return *window; }

	private:
		static EngineLoop* instance;

		bool running = true;
		EventDispatcher dispatcher;
		Unique<Window> window;

		Shared<Shader> shader;

		Shared<VertexBuffer> vbo;
		Shared<IndexBuffer> ibo;
		Shared<VertexArray> vao;

		Transform transform;
		Camera camera;

		bool OnWindowClose(Event& e);
		bool OnWindowResize(Event& e);

	};

}