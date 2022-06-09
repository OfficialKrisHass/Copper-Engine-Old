#include "cupch.h"
#include "Buffer.h"

#include "Engine/Renderer/RendererAPI.h"

#include "Engine/Platform/OpenGL/OpenGLBuffer.h"

namespace Copper {

	Shared<VertexBuffer> VertexBuffer::Create(std::vector<float> vertices) {

		switch (RendererAPI::GetAPI()) {

		case RendererAPI::API::None:	LogError("Graphics API: None is not supported currently! Vertex Buffer"); return nullptr;
		case RendererAPI::API::OpenGL:	return CreateShared<OpenGLVertexBuffer>(vertices);

		}

		LogError("Graphics API: None is not supported currently! Vertex Buffer");
		return nullptr;

	}

	Shared<IndexBuffer> IndexBuffer::Create(std::vector<uint32_t> indices) {

		switch (RendererAPI::GetAPI()) {

		case RendererAPI::API::None:	LogError("Graphics API: None is not supported currently! Vertex Buffer"); return nullptr;
		case RendererAPI::API::OpenGL:	return CreateShared<OpenGLIndexBuffer>(indices);

		}

		LogError("Graphics API: None is not supported currently! Vertex Buffer");
		return nullptr;

	}

}