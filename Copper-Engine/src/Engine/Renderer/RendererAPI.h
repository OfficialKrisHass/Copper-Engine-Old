#pragma once

#include "Engine/Core/Core.h"

#include "Engine/Renderer/VertexArray.h"
#include "Engine/Renderer/Shader.h"

#include "Engine/Scene/Transform.h"
#include "Engine/Scene/Camera.h"

namespace Copper {

	class RendererAPI {

	public:
		enum class API {

			None = 0,
			OpenGL

		};

	public:
		static Unique<RendererAPI> Create();
		virtual ~RendererAPI() = default;

		inline static API GetAPI() { return api; }

		virtual void Initialize() = 0;
		virtual void ClearColor(float r, float g, float b) = 0;
		virtual void SetViewport(uint32_t width, uint32_t height) = 0;

		virtual void SetShader(Shared<Shader> shader) = 0;

		virtual void Render(Shared<VertexArray> vao, Transform transform, Camera camera) = 0;

	private:
		static API api;

	};

}