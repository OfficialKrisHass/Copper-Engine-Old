//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#include "cupch.h"
#include "OpenGLShader.h"

#include "Copper/Utilities/FileUtils.h"

#include <GLAD/glad.h>

namespace Copper {

	int success;
	char infoLog[512];

	OpenGLShader::OpenGLShader(const char* vertexPath, const char* fragmentPath) {

		CreateShader(vertexPath, GL_VERTEX_SHADER, &vertexID);
		CreateShader(fragmentPath, GL_FRAGMENT_SHADER, &fragmentID);

		ID = glCreateProgram();

		glAttachShader(ID, vertexID);
		glAttachShader(ID, fragmentID);
		glLinkProgram(ID);

		CheckShader(ID);

		glDeleteShader(vertexID);
		glDeleteShader(fragmentID);

	}

	OpenGLShader::~OpenGLShader() {

		Log("Deleting Shader {0}", ID);
		glDeleteProgram(ID);

	}

	void OpenGLShader::CreateShader(const char* path, int type, unsigned int* id) {

		if (type != GL_VERTEX_SHADER && type != GL_FRAGMENT_SHADER) { LogError("Unkown Shader Type!"); return; }

		*id = glCreateShader(type);

		std::string source = ReadFile(path);
		const char* src = source.c_str();

		glShaderSource(*id, 1, &src, NULL);
		glCompileShader(*id);

		CheckShader(type, *id);

	}

	void OpenGLShader::CheckShader(int type, unsigned int id) {

		glGetShaderiv(id, GL_COMPILE_STATUS, &success);

		if (!success) {

			glGetShaderInfoLog(id, 512, NULL, infoLog);

			switch (type) {

			case GL_VERTEX_SHADER: LogError("Vertex Shader Compiling Error:\n\n {0}", infoLog); break;
			case GL_FRAGMENT_SHADER: LogError("Fragment Shader Compiling Error:\n\n {0}", infoLog);

			}

		}

	}

	void OpenGLShader::CheckShader(unsigned int id) {

		glGetProgramiv(id, GL_LINK_STATUS, &success);

		if (!success) {

			glGetProgramInfoLog(id, 512, NULL, infoLog);
			
			LogError("Shader Linking Error:\n\n {0}", infoLog);

		}

	}

	void OpenGLShader::Bind() const {

		glUseProgram(ID);

	}

	void OpenGLShader::Unbind() const {

		glUseProgram(0);

	}

	void OpenGLShader::SetMat4(glm::mat4 mat, const char* name) const {

		glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, GL_FALSE, glm::value_ptr(mat));

	}

}