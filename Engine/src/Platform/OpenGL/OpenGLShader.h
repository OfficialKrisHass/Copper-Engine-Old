//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#pragma once

#include "Copper/Core/Core.h"

#include "Copper/Renderer/Shader.h"

namespace Copper {

	class OpenGLShader : public Shader {

	public:
		OpenGLShader(const char* vertexPath, const char* fragmentPath);
		virtual ~OpenGLShader();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		inline virtual unsigned int GetID() const override { return ID; }

		virtual void SetMat4(glm::mat4 mat, const char* name) const override;

	private:
		unsigned int ID;

		unsigned int vertexID;
		unsigned int fragmentID;

		void CreateShader(const char* path, int type, unsigned int* id);

		void CheckShader(int type, unsigned int id);
		void CheckShader(unsigned int id);

	};

}