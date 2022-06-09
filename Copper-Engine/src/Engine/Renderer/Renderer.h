#pragma once

#include "Engine/Core/Core.h"

#include "Engine/Renderer/VertexArray.h"
#include "Engine/Renderer/Shader.h"

#include "Engine/Scene/Transform.h"
#include "Engine/Scene/Camera.h"

namespace Copper {

	class RendererAPI;

	class Renderer {

	public:
		static void Initialize();
		static void ClearColor(float r, float g, float b);
		static void SetViewport(uint32_t width, uint32_t height);

		static void SetShader(Shared<Shader> shader);

		static void Render(Shared<VertexArray> vao, Transform transform, Camera camera);

	private:
		static Unique<RendererAPI> api;

	};

}