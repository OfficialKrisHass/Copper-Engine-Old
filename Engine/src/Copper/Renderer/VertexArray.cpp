//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//The VertexArray Base source file. As with everything else, here we only define
//The Create function and return the API specific implementation of the functions
//From the Base class (VertexArray.h)

#include "cupch.h"
#include "VertexArray.h"

//Incude the Renderer so that we can know what Rendeing API we are using
#include "Copper/Renderer/Renderer.h"

//Incude the API Implementations of the VertexArray
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Copper {

	//The Create Function
	Shared<VertexArray> VertexArray::Create() {

		//Switch statement with the Rendering API we are using
		switch(Renderer::GetAPI()) {

		case Renderer::RendererAPI::None: LogError("RendererAPI::None is not supported! File VertexArray.cpp"); return nullptr; //No Rendering API
		case Renderer::RendererAPI::OpenGL: return CreateShared<OpenGLVertexArray>(); //OpenGL

		}

		//This code will only run if the Rendering API is unkown
		LogError("Unkown Rendering API! File VertexArray.cpp");
		return nullptr;

	}

}