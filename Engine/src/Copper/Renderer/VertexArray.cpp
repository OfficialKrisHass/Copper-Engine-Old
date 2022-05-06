//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#include "cupch.h"
#include "VertexArray.h"

#include "Copper/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Copper {

	Shared<VertexArray> VertexArray::Create() {

		switch(Renderer::GetAPI()) {

		case Renderer::RendererAPI::None: LogError("RendererAPI::None is not supported! File VertexArray.cpp"); return nullptr;
		case Renderer::RendererAPI::OpenGL: return CreateShared<OpenGLVertexArray>();

		}

		LogError("Unkown Rendering API! File Buffer.cpp");
		return nullptr;

	}

}