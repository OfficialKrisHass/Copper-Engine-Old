//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#pragma once

#include "Copper/Core/Core.h"

#include <GLM/glm.hpp>

namespace Copper {

	class Transform {

	public:
		Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);

		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;

		glm::mat4 CreateModelMatrix();

	private:

	};

}