#pragma once

#include "Engine/Core/Core.h"

#include "Engine/Renderer/Shader.h"

namespace Copper {

	class OpenGLShader : public Shader {

	public:
		OpenGLShader(const char* vertexPath, const char* fragmentPath);
		virtual ~OpenGLShader();

		virtual void Bind() override;
		virtual void Unbind() override;

		virtual void LoadMat4(glm::mat4 mat, const char* name) override;

	private:
		uint32_t ID;
		uint32_t vertex;
		uint32_t fragment;

		void CreateShader(int type, const char* path, uint32_t& id);
		void CheckForErrors(int type, uint32_t id); //Shader Compile Errors
		void CheckForErrors(uint32_t id); //Shader Program Linking errors

	};

}