#include "cupch.h"
#include "Shader.h"

#include "Engine/Renderer/RendererAPI.h"

#include "Engine/Platform/OpenGL/OpenGLShader.h"

namespace Copper {

	Shared<Shader> Shader::Create(const char* vertexPath, const char* fragmentPath) {

		switch (RendererAPI::GetAPI()) {

		case RendererAPI::API::None:	LogError("Graphics API: None is not supported currently! Shader"); return nullptr;
		case RendererAPI::API::OpenGL:	return CreateShared<OpenGLShader>(vertexPath, fragmentPath);

		}

		LogError("Graphics API: None is not supported currently! Shader");
		return nullptr;

	}

}