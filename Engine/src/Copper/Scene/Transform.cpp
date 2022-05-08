//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#include "cupch.h"
#include "Transform.h"

namespace Copper {

	Transform::Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) : position(position), rotation(rotation), scale(scale) {}

	glm::mat4 Transform::CreateModelMatrix() {

		glm::mat4 ret(1.0f);

		ret = glm::translate(ret, position);
		
		ret = glm::rotate(ret, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		ret = glm::rotate(ret, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		ret = glm::rotate(ret, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

		ret = glm::scale(ret, scale);

		return ret;

	}

}