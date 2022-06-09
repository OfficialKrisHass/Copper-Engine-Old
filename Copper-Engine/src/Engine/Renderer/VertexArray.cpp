#include "cupch.h"
#include "VertexArray.h"

#include "Engine/Renderer/RendererAPI.h"

#include "Engine/Platform/OpenGL/OpenGLVertexArray.h"

namespace Copper {

	Shared<VertexArray> VertexArray::Create() {

		switch (RendererAPI::GetAPI()) {

		case RendererAPI::API::None:	LogError("Graphics API: None is not supported currently! Vertex Array"); return nullptr;
		case RendererAPI::API::OpenGL:	return CreateShared<OpenGLVertexArray>();

		}

		LogError("Graphics API: None is not supported currently! Vertex Array");
		return nullptr;

	}

}