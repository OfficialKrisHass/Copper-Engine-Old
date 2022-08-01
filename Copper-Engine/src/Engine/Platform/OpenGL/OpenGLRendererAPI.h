#pragma once

#include "Engine/Core/Core.h"

#include "Engine/Renderer/RendererAPI.h"

namespace Copper {

	class OpenGLRendererAPI : public RendererAPI {

	public:
		OpenGLRendererAPI() {}

		virtual void Initialize() override;
		virtual void ClearColor(float r, float g, float b) override;
		virtual void SetViewport(uint32_t width, uint32_t height) override;

		inline virtual void SetShader(Shared<Shader> shader) override { this->shader = shader; }

		virtual void Render(Mesh* mesh, Camera* camera) override;

	private:
		Shared<Shader> shader;

	};

}