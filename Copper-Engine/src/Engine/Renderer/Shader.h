#pragma once

#include "Engine/Core/Core.h"

#include <glm/glm.hpp>

namespace Copper {

	class Shader {

	public:
		static Shared<Shader> Create(const char* vertexPath, const char* fragmentPath);

		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		virtual void LoadMat4(glm::mat4 mat, const char* name) = 0;

	private:
		//

	};

}