//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//The Source File for the Renderer. Here We only declare the static Create Functions,
//and based on what rendering API we are using, return that API implementation of the Renderer.

#include "cupch.h"
#include "Renderer.h"

//Include our Platform Implementations of the Renderer
#include "Platform/OpenGL/OpenGLRenderer.h"

namespace Copper {

	//Create the API and set it to OpenGL
	Renderer::RendererAPI Renderer::api = Renderer::RendererAPI::OpenGL;

	//The Create Function
	Unique<Renderer> Renderer::Create() {

		//Switch case for the Rendering API we are using
		switch (api) {

		case RendererAPI::None: EngineLogError("RendererAPI::None is not supported! Renderer.cpp"); return nullptr; //No Rendering API
		case RendererAPI::OpenGL: return CreateUnique<OpenGLRenderer>(); //OpenGL

		}

		//This code will only run if the client is using unkown rendering API
		EngineLogError("Unkown Rendering API! File Renderer.cpp");
		return nullptr;
	}

}