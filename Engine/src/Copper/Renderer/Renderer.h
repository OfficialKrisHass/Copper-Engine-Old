//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//The Header for the Main 

#pragma once

#include "cupch.h"

#include "Copper/Core/Core.h"

#include "Copper/Renderer/VertexArray.h"
#include "Copper/Renderer/Shader.h"

#include "Copper/Scene/Mesh.h"
#include "Copper/Scene/Camera.h"

namespace Copper {

	class Renderer {

	public:
		enum class RendererAPI {

			None = 0,
			OpenGL

		};

		static Unique<Renderer> Create();
		virtual ~Renderer() = default;

		virtual void Initialize() = 0;
		virtual void ClearColor(float r, float g, float b) = 0;

		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
		virtual void SetShader(Shared<Shader> shader) = 0;

		virtual void Render(const Shared<Mesh>& mesh, const Shared<Camera>& cam) = 0;

		inline static RendererAPI GetAPI() { return api; }

	private:
		static RendererAPI api;

	};

}