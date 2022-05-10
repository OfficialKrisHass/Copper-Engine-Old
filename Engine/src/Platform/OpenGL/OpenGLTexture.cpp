//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#include "cupch.h"
#include "OpenGLTexture.h"

#include <GLAD/glad.h>
#include <stb/stb_image.h>

namespace Copper {

	OpenGLTexture::OpenGLTexture(const char* path) {

		glGenTextures(1, &ID);
		Bind();

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int width, height, nChannels;
		stbi_set_flip_vertically_on_load(true);

		unsigned char* data = stbi_load(path, &width, &height, &nChannels, 0);

		if (data) {

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);

		} else { EngineLogError("Could Not Load Image: {0}", path); }

		stbi_image_free(data);

	}

	OpenGLTexture::~OpenGLTexture() {}

	void OpenGLTexture::Bind() {

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, ID);

	}

	void OpenGLTexture::Unbind() {
		
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, 0);
		
	}

}