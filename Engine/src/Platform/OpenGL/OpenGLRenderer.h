//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//This is the Header file for the OpenGL implementation of the Renderer. Here we give
//The functions that were declared in the Base Renderer Class an actual body that can do work

#pragma once

#include "Copper/Renderer/Renderer.h"

namespace Copper {

	//OpenGL Renderer Implementation class
	class OpenGLRenderer : public Renderer {

	public:
		//Initialize and Clear the background functions
		virtual void Initialize() override;
		virtual void ClearColor(float r, float g, float b) override;

		//Functions to set the Renderer
		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
		inline virtual void SetShader(Shared<Shader> shader) override { this->shader = shader; }

		//Render the Object with a Camera
		virtual void Render(const Shared<Mesh>& mesh, const Shared<Camera>& cam) override;

	private:
		//Shader that the Renderer is using
		Shared<Shader> shader;

	};

}