#include "cupch.h"
#include "OpenGLBuffer.h"

#include <GLAD/glad.h>

namespace Copper {

	OpenGLVertexBuffer::OpenGLVertexBuffer(std::vector<float> vertices) {

		glGenBuffers(1, &ID);

		glBindBuffer(GL_ARRAY_BUFFER, ID);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer() {

		glDeleteBuffers(1, &ID);

	}

	void OpenGLVertexBuffer::Bind()   { glBindBuffer(GL_ARRAY_BUFFER, ID); }
	void OpenGLVertexBuffer::Unbind() { glBindBuffer(GL_ARRAY_BUFFER, 0); }

	//----------------------------
	//--------INDEX BUFFER--------
	//----------------------------

	OpenGLIndexBuffer::OpenGLIndexBuffer(std::vector<uint32_t> indices) {

		this->count = (uint32_t) indices.size();

		glGenBuffers(1, &ID);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), indices.data(), GL_STATIC_DRAW);

	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer() {

		glDeleteBuffers(1, &ID);

	}

	void OpenGLIndexBuffer::Bind()   { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID); }
	void OpenGLIndexBuffer::Unbind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

}