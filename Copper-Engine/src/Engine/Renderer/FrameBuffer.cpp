#include "cupch.h"
#include "FrameBuffer.h"

#include "Engine/Renderer/RendererAPI.h"

#include "Engine/Platform/OpenGL/OpenGLFrameBuffer.h"

namespace Copper {

	Shared<FrameBuffer> FrameBuffer::Create(UVector2 size) {

		switch (RendererAPI::GetAPI()) {

		case RendererAPI::API::None: LogError("Graphics API: None is not supported currently! Frame Buffer"); return nullptr;
		case RendererAPI::API::OpenGL: return CreateShared<OpenGLFrameBuffer>(size);

		}

		LogError("Graphics API: None is not supported currently! Frame Buffer");
		return nullptr;

	}

}