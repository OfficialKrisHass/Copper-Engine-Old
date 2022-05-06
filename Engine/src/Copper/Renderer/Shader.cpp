//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#include "cupch.h"
#include "Shader.h"

#include "Copper/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLShader.h"

namespace Copper {

	Shared<Shader> Shader::Create(const char* vertexPath, const char* fragmentPath) {

		switch (Renderer::GetAPI()) {

		case Renderer::RendererAPI::None: LogError("RendererAPI::None is not supported! File Shader.cpp"); return nullptr;
		case Renderer::RendererAPI::OpenGL: return CreateShared<OpenGLShader>(vertexPath, fragmentPath);

		}

		LogError("Unkown Rendering API! File Shader.cpp");
		return nullptr;

	}

}