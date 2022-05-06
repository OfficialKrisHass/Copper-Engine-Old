//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#include "cupch.h"
#include "Renderer.h"

#include "Platform/OpenGL/OpenGLRenderer.h"

namespace Copper {

	Renderer::RendererAPI Renderer::api = Renderer::RendererAPI::OpenGL;

	Unique<Renderer> Renderer::Create() {

		switch (api) {

		case RendererAPI::None: LogError("RendererAPI::None is not supported!"); return nullptr;
		case RendererAPI::OpenGL: return CreateUnique<OpenGLRenderer>();

		}

		LogError("Unkown Rendering API! File Renderer.cpp");
		return nullptr;
	}

}