#pragma once

#include "Engine/Core/Core.h"

#include <glm/glm.hpp>

namespace Copper {

	class Camera {

	public:
		Camera() = default;
		Camera(Vector3 position, Vector3 rotation, float fov)
			: position(position), rotation(rotation), fov(fov), nearPlane(0.1f), farPlane(1000.0f) {}

		Vector3 position;
		Vector3 rotation;

		glm::mat4 CreateViewMatrix();
		glm::mat4 CreateProjectionMatrix();

	private:
		float fov;
		float nearPlane;
		float farPlane;

		Vector3 forward = Vector3(0.0f, 0.0f, -1.0f);
		Vector3 up = Vector3(0.0f, 1.0f, 0.0f);

	};

}