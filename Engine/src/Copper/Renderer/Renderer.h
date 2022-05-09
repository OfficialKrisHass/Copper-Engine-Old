//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//The Header for the Renderer Base. Here we declare functions that we can use and then
//we define those functions in a Specific Renderig API Implementation. At this current
//Time the Renderer is not done, It can Render 3D Objects with a fully controlable
//3D Camera but it is just a prototype that has the least things to be functional.

#pragma once

//Includes (Obviously)
#include "cupch.h"

#include "Copper/Core/Core.h"

#include "Copper/Renderer/VertexArray.h"
#include "Copper/Renderer/Shader.h"

#include "Copper/Scene/Mesh.h"
#include "Copper/Scene/Camera.h"

namespace Copper {

	//The Base Renderer Class.
	class Renderer {

	public:
		//enum for Rendering APIs
		enum class RendererAPI {

			None = 0,
			OpenGL

		};

		//Static Create functions that returns unique pointer, and a default destructor
		static Unique<Renderer> Create();
		virtual ~Renderer() = default;

		//Simple Initialize Function and a Clear Color that just colors the background
		virtual void Initialize() = 0;
		virtual void ClearColor(float r, float g, float b) = 0;

		//Setting functions
		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
		virtual void SetShader(Shared<Shader> shader) = 0;

		//The Core Render Function that renderes the Whole scene
		virtual void Render(const Shared<Mesh>& mesh, const Shared<Camera>& cam) = 0;

		//Function to get the API we are using
		inline static RendererAPI GetAPI() { return api; }

	private:
		static RendererAPI api;

	};

}