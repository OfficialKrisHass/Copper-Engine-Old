//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//Source file of the OpenGL Shader implementation.

#include "cupch.h"
#include "OpenGLShader.h"

#include "Copper/Utilities/FileUtils.h"

#include <GLAD/glad.h>

namespace Copper {

	//Variables that we use to check if the Shaders is working
	int success;
	char infoLog[512];

	//Constructor of the Shader
	OpenGLShader::OpenGLShader(const char* vertexPath, const char* fragmentPath) {

		//Create the separate shaders and store their ID in the ID variables
		CreateShader(vertexPath, GL_VERTEX_SHADER, &vertexID);
		CreateShader(fragmentPath, GL_FRAGMENT_SHADER, &fragmentID);

		//Create the Shader Program
		ID = glCreateProgram();

		//Attach the separate Shaders and Link the Shader Program together
		glAttachShader(ID, vertexID);
		glAttachShader(ID, fragmentID);
		glLinkProgram(ID);

		//Check if the Shader Program was linked correctly
		CheckShader(ID);

		//Delete the separate Shaders, we won't need them anymore when we have the Shader Program
		glDeleteShader(vertexID);
		glDeleteShader(fragmentID);

	}

	//Shader Destructor that deletes the Shader Program
	OpenGLShader::~OpenGLShader() {

		Log("Deleting Shader {0}", ID);
		glDeleteProgram(ID);

	}

	//Function to Create the separate shaders
	void OpenGLShader::CreateShader(const char* path, int type, unsigned int* id) {

		//Check if the Shader Type is correct, if not return
		if (type != GL_VERTEX_SHADER && type != GL_FRAGMENT_SHADER) { LogError("Unkown Shader Type!"); return; }

		//Set the original id of the separate Shader to new Shader of the given type
		*id = glCreateShader(type);

		//Read the Shader file that was given to us
		//NOTE: For some fucking reason this won't work if the function would already
		//Convert the string into char array but if I convert it the same way here it
		//magically works, WHY. WHY C++
		std::string source = ReadFile(path);
		const char* src = source.c_str();

		//Set the Shader source to what we got from the Shader and compile the Shader
		glShaderSource(*id, 1, &src, NULL);
		glCompileShader(*id);

		//Check if the Shader compilation succeeded
		CheckShader(type, *id);

	}

	//Function to Check if the Compilaton of the separate Shaders was successful
	void OpenGLShader::CheckShader(int type, unsigned int id) {

		//Get the Shader Compile Status and store it in the Success integer
		glGetShaderiv(id, GL_COMPILE_STATUS, &success);

		//If the compilation failed
		if (!success) {

			//Get the Info Log of the reason why the compilation failed
			glGetShaderInfoLog(id, 512, NULL, infoLog);

			//Switch for the Shader Type
			switch (type) {

			case GL_VERTEX_SHADER: LogError("Vertex Shader Compiling Error:\n\n {0}", infoLog); break; //Vertex Shader: Log the Error Message
			case GL_FRAGMENT_SHADER: LogError("Fragment Shader Compiling Error:\n\n {0}", infoLog); //Fragment Shader: Log the Error Message

			}

		}

	}

	//Function to Check if the Linking of the Shader Program was successful
	void OpenGLShader::CheckShader(unsigned int id) {

		//Get the Shader Program Link status and store it in the Success integer
		glGetProgramiv(id, GL_LINK_STATUS, &success);

		if (!success) {

			//Get the Info Lof of the reason why the Linking failed
			glGetProgramInfoLog(id, 512, NULL, infoLog);
			
			//Log the Error with the InfoLog
			LogError("Shader Linking Error:\n\n {0}", infoLog);

		}

	}

	//Function to Bind/Use the Shader Program
	void OpenGLShader::Bind() const {

		glUseProgram(ID);

	}

	//Function to Unbind/Unuse the Shader Program
	void OpenGLShader::Unbind() const {

		glUseProgram(0);

	}

	//---------------------------------
	//-----Setting Shader Uniforms-----
	//---------------------------------

	//Set Matrix 4x4 uniform
	void OpenGLShader::SetMat4(glm::mat4 mat, const char* name) const {

		//Set the Uniform with the Location and the actualy Data of the Matrix
		glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, GL_FALSE, glm::value_ptr(mat));

	}

	void OpenGLShader::SetInt(int value, const char* name) const {

		glUniform1i(glGetUniformLocation(ID, name), value);

	}

}