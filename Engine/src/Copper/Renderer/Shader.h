//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//The Core Header for the Shader class. A Shader is a little program that runs on the
//GPU and it is how the Vertices should be modified. There are 2 types of Shaders:
//
//Vertex Shader: gets runned once per every Vertex and modifies where on the screen
//The Vertex should be rendered. Here we make the Game Look 3D.
//
//Fragment Shader: Fragment Shader is runned once per every pixel of the object
//and colors that specific pixel. Here we calculate Lightning and Textures.

#pragma once

#include "Copper/Core/Core.h"

#include <GLM/glm.hpp>

namespace Copper {

	//The Core Shader Class
	class Shader {

	public:
		//A Static Create function that returns Shared pointer and, default destructor
		static Shared<Shader> Create(const char* vertexPath, const char* fragmentPath);
		virtual ~Shader() = default;

		//Bind and unbind functions. Before we can use the Shader we need to Bind it
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		//Get the Shader ID
		virtual unsigned int GetID() const = 0;

		//Uniform Functions. Uniforms are variables in the Shaders that we can set
		virtual void SetMat4(glm::mat4 mat, const char* name) const = 0;
		virtual void SetInt(int value, const char* name) const = 0;

	};

}