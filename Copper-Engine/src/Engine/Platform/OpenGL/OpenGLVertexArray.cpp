#include "cupch.h"
#include "OpenGLVertexArray.h"

#include <GLAD/glad.h>

namespace Copper {

	OpenGLVertexArray::OpenGLVertexArray() {

		glGenVertexArrays(1, &ID);
		glBindVertexArray(ID);

	}

	void OpenGLVertexArray::AddVertexBuffer(Shared<VertexBuffer> vbo) {

		glBindVertexArray(ID);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
		glEnableVertexAttribArray(0);

	}

	void OpenGLVertexArray::AddIndexBuffer(Shared<IndexBuffer> ibo) {

		glBindVertexArray(ID);
		ibo->Bind();

		this->ibo = ibo;

	}

	void OpenGLVertexArray::Bind() { glBindVertexArray(ID); }
	void OpenGLVertexArray::Unbind() { glBindVertexArray(0); }

}