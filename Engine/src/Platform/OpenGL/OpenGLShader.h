//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//This is the Header File for the OpenGL Implementation of the Shader. Here we give
//the functions that were Declared in the Shader base class an actual body and functionality

#pragma once

#include "Copper/Core/Core.h"

#include "Copper/Renderer/Shader.h"

namespace Copper {

	//OpenGL implementation of the Shader class
	class OpenGLShader : public Shader {

	public:
		//Construct that takes path to the Vertex and Fragment Shaders and a destructor
		OpenGLShader(const char* vertexPath, const char* fragmentPath);
		virtual ~OpenGLShader();

		//Functions to Bind and Unbind our Shader
		virtual void Bind() const override;
		virtual void Unbind() const override;

		//Function to get the ID of the Shader
		inline virtual unsigned int GetID() const override { return ID; }

		//Functions to Set the Shader Uniforms
		virtual void SetMat4(glm::mat4 mat, const char* name) const override;
		virtual void SetInt(int value, const char* name) const override;

	private:
		//ID of the entire Shader Program
		unsigned int ID;

		//ID of the separate Vertex and Fragment Shaders
		unsigned int vertexID;
		unsigned int fragmentID;

		//Function that creates the separate Shaders
		void CreateShader(const char* path, int type, unsigned int* id);

		//Functions to check the seperate Shaders and the Shader program if there
		//weren't any problems with compiling or linking.
		void CheckShader(int type, unsigned int id);
		void CheckShader(unsigned int id);

	};

}