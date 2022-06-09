#include "cupch.h"
#include "OpenGLRendererAPI.h"

#include <GLAD/glad.h>

namespace Copper {

	void OpenGLRendererAPI::Initialize() {

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable(GL_DEPTH_TEST);

		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glFrontFace(GL_CCW);

		glPointSize(10.0f);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	}

	void OpenGLRendererAPI::ClearColor(float r, float g, float b) {

		glClearColor(r, g, b, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	}

	void OpenGLRendererAPI::SetViewport(uint32_t width, uint32_t height) {

		glViewport(0, 0, width, height);

	}

	void OpenGLRendererAPI::Render(Shared<VertexArray> vao, Transform transform, Camera camera) {

		vao->Bind();
		shader->Bind();

		shader->LoadMat4(transform.CreateModelMatrix(),   "model");
		shader->LoadMat4(camera.CreateViewMatrix(),		  "view");
		shader->LoadMat4(camera.CreateProjectionMatrix(), "projection");

		glDrawElements(GL_TRIANGLES, vao->VertexCount(), GL_UNSIGNED_INT, 0);

	}

}