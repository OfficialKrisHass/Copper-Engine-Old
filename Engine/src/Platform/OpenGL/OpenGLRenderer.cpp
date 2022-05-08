//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#include "cupch.h"
#include "OpenGLRenderer.h"

#include <GLAD/glad.h>

namespace Copper {

	void OpenGLRenderer::Initialize() {

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable(GL_DEPTH_TEST);

	}

	void OpenGLRenderer::ClearColor(float r, float g, float b) {

		glClearColor(r, g, b, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

	}

	void OpenGLRenderer::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {

		glViewport(x, y, width, height);

	}

	void OpenGLRenderer::Render(const Shared<Mesh>& mesh, const Shared<Camera>& cam) {

		mesh->BindVAO();
		shader->Bind();

		shader->SetMat4(mesh->transform->CreateModelMatrix(), "Model");
		shader->SetMat4(cam->CreateViewMatrix(), "View");
		shader->SetMat4(cam->CreateProjectionMatrix(), "Projection");

		cam->Move();

		glDrawElements(GL_TRIANGLES, mesh->GetVertexCount(), GL_UNSIGNED_INT, 0);

	}

}