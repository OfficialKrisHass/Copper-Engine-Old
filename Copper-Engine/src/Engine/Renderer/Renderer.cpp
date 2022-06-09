#include "cupch.h"
#include "Renderer.h"

#include "Engine/Renderer/RendererAPI.h"

namespace Copper {

	Unique<RendererAPI> Renderer::api = nullptr;

	void Renderer::Initialize() {

		api = RendererAPI::Create();
		api->Initialize();

	}

	void Renderer::ClearColor(float r, float g, float b) {

		api->ClearColor(r, g, b);

	}

	void Renderer::SetViewport(uint32_t width, uint32_t height) {

		api->SetViewport(width, height);

	}

	void Renderer::SetShader(Shared<Shader> shader) {

		api->SetShader(shader);

	}

	void Renderer::Render(Shared<VertexArray> vao, Transform transform, Camera camera) {

		api->Render(vao, transform, camera);

	}

}