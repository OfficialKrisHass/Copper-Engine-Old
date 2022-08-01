#include "cupch.h"
#include "Transform.h"

#include <glm/ext/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

namespace Copper {

	glm::mat4 Transform::CreateModelMatrix() {

		glm::mat4 model(1.0f);

		model = glm::translate(model, (glm::vec3) position);

		model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

		model = glm::scale(model, (glm::vec3) scale);

		return model;

	}

}