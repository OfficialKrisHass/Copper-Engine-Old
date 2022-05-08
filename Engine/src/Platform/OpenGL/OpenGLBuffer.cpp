//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#include "cupch.h"
#include "OpenGLBuffer.h"

#include <GLAD/glad.h>

namespace Copper {

	OpenGLVertexBuffer::OpenGLVertexBuffer(std::vector<float> vertices) {

		glGenBuffers(1, &ID);

		Bind();
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer() {

		Log("Deleting Vertex Buffer {0}", ID);
		glDeleteBuffers(1, &ID);

	}

	void OpenGLVertexBuffer::Bind() {

		glBindBuffer(GL_ARRAY_BUFFER, ID);

	}

	void OpenGLVertexBuffer::Unbind() {

		glBindBuffer(GL_ARRAY_BUFFER, 0);

	}

	OpenGLIndexBuffer::OpenGLIndexBuffer(std::vector<uint32_t> indices) {

		this->count = (uint32_t) indices.size();

		glGenBuffers(1, &ID);
		
		Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer() {

		Log("Deleting Index Buffer {0}", ID);
		glDeleteBuffers(1, &ID);

	}

	void OpenGLIndexBuffer::Bind() {

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);

	}

	void OpenGLIndexBuffer::Unbind() {

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	}

	uint32_t OpenGLIndexBuffer::Count() {

		return count;

	}

}