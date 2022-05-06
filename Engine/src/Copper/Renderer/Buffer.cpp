//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#include "cupch.h"
#include "Buffer.h"

#include "Copper/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Copper {

	Shared<VertexBuffer> VertexBuffer::Create(std::vector<float> vertices) {

		switch (Renderer::GetAPI()) {

		case Renderer::RendererAPI::None: LogError("RenderAPI::None is not supported! File Buffer.cpp"); return nullptr;
		case Renderer::RendererAPI::OpenGL: return CreateShared<OpenGLVertexBuffer>(vertices);

		}
		
		LogError("Unkown Rendering API! File Buffer.cpp");
		return nullptr;

	}

	Shared<IndexBuffer> IndexBuffer::Create(std::vector<uint32_t> indices) {

		switch (Renderer::GetAPI()) {

		case Renderer::RendererAPI::None: LogError("RenderAPI::None is not supported! File Buffer.cpp"); return nullptr;
		case Renderer::RendererAPI::OpenGL: return CreateShared<OpenGLIndexBuffer>(indices);

		}

		LogError("Unkown Rendering API! File Buffer.cpp");
		return nullptr;

	}

}