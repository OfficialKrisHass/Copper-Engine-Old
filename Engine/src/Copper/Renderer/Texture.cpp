//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#include "cupch.h"
#include "Texture.h"

#include "Copper/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLTexture.h"

namespace Copper {

	Shared<Texture> Texture::Create(const char* path) {

		switch (Renderer::GetAPI()) {

		case Renderer::RendererAPI::None: LogError("RendererAPI::None is not supported! File Texture.cpp"); return nullptr;
		case Renderer::RendererAPI::OpenGL: return CreateShared<OpenGLTexture>(path);

		}

		LogError("Unkown Rendeing API! File Texture.cpp");
		return nullptr;

	}

}