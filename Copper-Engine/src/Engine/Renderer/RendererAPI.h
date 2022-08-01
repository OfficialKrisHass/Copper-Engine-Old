#pragma once

#include "Engine/Core/Core.h"

#include "Engine/Renderer/VertexArray.h"
#include "Engine/Renderer/Shader.h"

#include "Engine/Scene/Components/Transform.h"
#include "Engine/Scene/Components/Mesh.h"
#include "Engine/Scene/Components/Camera.h"

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

		virtual void Render(Mesh* mesh, Camera* camera) = 0;

	private:
		static API api;

	};

}