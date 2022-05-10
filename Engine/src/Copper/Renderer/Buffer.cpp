//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//This is the Buffer Source file. Here we only choose what Implementation of the Buffers
//We should return and then create those Implementations and return them

#include "cupch.h"
#include "Buffer.h"

#include "Copper/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Copper {

	//The Create function that returns a Shared Pointer of the implementation that we are using
	Shared<VertexBuffer> VertexBuffer::Create(std::vector<float> vertices) {

		//Switch case based on what Rendering API we are using
		switch (Renderer::GetAPI()) {

		case Renderer::RendererAPI::None: EngineLogError("RenderAPI::None is not supported! File Buffer.cpp"); return nullptr; //No Rendering API
		case Renderer::RendererAPI::OpenGL: return CreateShared<OpenGLVertexBuffer>(vertices); //OpenGL

		}
		
		//this code runs only if the Rendering API is unkown
		EngineLogError("Unkown Rendering API! File Buffer.cpp");
		return nullptr;

	}

	//The Create function that returns a Shared Pointer of the implementation that we are using
	Shared<IndexBuffer> IndexBuffer::Create(std::vector<uint32_t> indices) {

		//Switch case based on what Rendering API we are using
		switch (Renderer::GetAPI()) {

		case Renderer::RendererAPI::None: EngineLogError("RenderAPI::None is not supported! File Buffer.cpp"); return nullptr; //No Rendering API
		case Renderer::RendererAPI::OpenGL: return CreateShared<OpenGLIndexBuffer>(indices); //OpenGL

		}
		
		//this code runs only if the Rendering API is unkown
		EngineLogError("Unkown Rendering API! File Buffer.cpp");
		return nullptr;

	}

}