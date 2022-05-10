//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//The Source file for the Shader. As in every other Rendering file. Here we only
//Make the Create function and return a specific API implementation of the Shader

#include "cupch.h"
#include "Shader.h"

//Include the Renderer so that we can get what API we are using
#include "Copper/Renderer/Renderer.h"

//API Specific Implementations of the Shader
#include "Platform/OpenGL/OpenGLShader.h"

namespace Copper {

	//Create Function
	Shared<Shader> Shader::Create(const char* vertexPath, const char* fragmentPath) {

		//Switch case with what API we are using
		switch (Renderer::GetAPI()) {

		case Renderer::RendererAPI::None: EngineLogError("RendererAPI::None is not supported! File Shader.cpp"); return nullptr; //No Rendering API
		case Renderer::RendererAPI::OpenGL: return CreateShared<OpenGLShader>(vertexPath, fragmentPath); //OpenGL

		}

		//This code runs only if the API is unkown
		EngineLogError("Unkown Rendering API! File Shader.cpp");
		return nullptr;

	}

}