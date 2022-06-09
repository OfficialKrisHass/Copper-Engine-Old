#include "cupch.h"
#include "OpenGLShader.h"

#include "Engine/Utilities/FileUtils.h"

#include <GLAD/glad.h>
#include <glm/gtc/type_ptr.hpp>

namespace Copper {

	int success;
	char infoLog[512];

	OpenGLShader::OpenGLShader(const char* vertexPath, const char* fragmentPath) {
		
		CreateShader(GL_VERTEX_SHADER, vertexPath, vertex);
		CreateShader(GL_FRAGMENT_SHADER, fragmentPath, fragment);

		ID = glCreateProgram();

		glAttachShader(ID, vertex);
		glAttachShader(ID, fragment);
		glLinkProgram(ID);

		CheckForErrors(ID);

		glDeleteShader(vertex);
		glDeleteShader(fragment);
		
	}

	OpenGLShader::~OpenGLShader() { glDeleteProgram(ID); }

	void OpenGLShader::CreateShader(int type, const char* path, uint32_t& id) {

		if (type != GL_VERTEX_SHADER && type != GL_FRAGMENT_SHADER) { LogError("Unkown Shader Type!"); return; }

		id = glCreateShader(type);
		std::string source = Utilities::ReadFile(path);
		const char* src = source.c_str();

		glShaderSource(id, 1, &src, NULL);
		glCompileShader(id);

		CheckForErrors(type, id);

	}

	void OpenGLShader::CheckForErrors(int type, uint32_t id) {

		glGetShaderiv(id, GL_COMPILE_STATUS, &success);

		if (!success) {

			glGetShaderInfoLog(id, 512, NULL, infoLog);

			switch (type) {

			case GL_VERTEX_SHADER:   LogError("Vertex Shader Compiling Error:\n\n {0}", infoLog); break;
			case GL_FRAGMENT_SHADER: LogError("Fragment Shader Compiling Error:\n\n {0}", infoLog);

			}

		}

	}

	void OpenGLShader::CheckForErrors(uint32_t id) {

		glGetProgramiv(id, GL_LINK_STATUS, &success);

		if (!success) {

			glGetProgramInfoLog(id, 512, NULL, infoLog);

			LogError("Shader Linking Error:\n\n {0}", infoLog);

		}

	}

	void OpenGLShader::LoadMat4(glm::mat4 mat, const char* name) {

		glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, GL_FALSE, glm::value_ptr(mat));

	}

	void OpenGLShader::Bind() { glUseProgram(ID); }
	void OpenGLShader::Unbind() { glUseProgram(0); }

}