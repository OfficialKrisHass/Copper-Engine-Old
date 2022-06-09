#pragma once

#include "Engine/Core/Core.h"

#include <glm/glm.hpp>

namespace Copper {

	class Transform {

	public:
		Transform() = default;
		Transform(Vector3 position, Vector3 rotation, Vector3 scale) : position(position), rotation(rotation), scale(scale) {}

		Vector3 position;
		Vector3 rotation;
		Vector3 scale;

		glm::mat4 CreateModelMatrix();

	};

}