//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#include "cupch.h"
#include "OpenGLVertexArray.h"

#include <GLAD/glad.h>

namespace Copper {

	OpenGLVertexArray::OpenGLVertexArray() {

		glGenVertexArrays(1, &ID);

	}

	void OpenGLVertexArray::Bind() {

		glBindVertexArray(ID);

	}

	void OpenGLVertexArray::Unbind() {

		glBindVertexArray(0);

	}

	void OpenGLVertexArray::AddVertexBuffer(const Shared<VertexBuffer> vertexBuffer) {

		Bind();

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
		glEnableVertexAttribArray(0);

	}

	void OpenGLVertexArray::AddIndexBuffer(const Shared<IndexBuffer> indexBuffer) {

		Bind();
		indexBuffer->Bind();

		this->indexBuffer = indexBuffer;

	}

}