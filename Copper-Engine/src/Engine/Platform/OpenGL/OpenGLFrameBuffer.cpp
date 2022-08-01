#include "cupch.h"
#include "OpenGLFrameBuffer.h"

#include <GLAD/glad.h>

namespace Copper {

	OpenGLFrameBuffer::OpenGLFrameBuffer(UVector2 size) : size(size) {

		Recreate();

	}

	OpenGLFrameBuffer::~OpenGLFrameBuffer() {

		glDeleteFramebuffers(1, &id);

	}

	void OpenGLFrameBuffer::Recreate() {

		if (id) {

			glDeleteFramebuffers(1, &id);
			glDeleteTextures(1, &color);
			glDeleteTextures(1, &depth);

		}

		glCreateFramebuffers(1, &id);
		glBindFramebuffer(GL_FRAMEBUFFER, id);

		glCreateTextures(GL_TEXTURE_2D, 1, &color);
		glBindTexture(GL_TEXTURE_2D, color);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, size.x, size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, color, 0);

		glCreateTextures(GL_TEXTURE_2D, 1, &depth);
		glBindTexture(GL_TEXTURE_2D, depth);

		glTexStorage2D(GL_TEXTURE_2D, 1, GL_DEPTH24_STENCIL8, size.x, size.y);

		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_TEXTURE_2D, depth, 0);

		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {

			LogError("Frame Buffer is Incomplete");

		}

		glBindFramebuffer(GL_FRAMEBUFFER, 0);

	}

	void OpenGLFrameBuffer::Resize(UVector2 size) {

		this->size = size;

		Recreate();

	}

	void OpenGLFrameBuffer::Bind() {

		glBindFramebuffer(GL_FRAMEBUFFER, id);
		glViewport(0, 0, size.x, size.y);

	}

	void OpenGLFrameBuffer::Unbdind() {

		glBindFramebuffer(GL_FRAMEBUFFER, 0);

	}

}