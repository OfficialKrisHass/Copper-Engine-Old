#include "cupch.h"
#include "Transform.h"

#include <glm/ext/matrix_transform.hpp>

namespace Copper {

	glm::mat4 Transform::CreateModelMatrix() {

		glm::mat4 model(1.0f);

		model = glm::translate(model, position.ToGLM());

		model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

		model = glm::scale(model, scale.ToGLM());

		return model;

	}

}