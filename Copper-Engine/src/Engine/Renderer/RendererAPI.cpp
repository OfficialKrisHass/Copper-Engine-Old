#include "cupch.h"
#include "RendererAPI.h"

#include "Engine/Platform/OpenGL/OpenGLRendererAPI.h"

namespace Copper {

	RendererAPI::API RendererAPI::api = RendererAPI::API::OpenGL;

	Unique<RendererAPI> RendererAPI::Create() {

		switch (api) {

		case RendererAPI::API::None:	LogError("Graphics API: None is not supported currently! RendererAPI"); return nullptr;
		case RendererAPI::API::OpenGL:	return CreateUnique<OpenGLRendererAPI>();

		}

		LogError("Unkown RendererAPI. Class RendererAPI");
		return nullptr;

	}

}