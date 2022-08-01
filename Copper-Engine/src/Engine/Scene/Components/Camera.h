#pragma once

#include "Engine/Core/Core.h"

#include "Engine/Scene/Components/Component.h"

#include <glm/glm.hpp>

namespace Copper {

	class Camera : public Component {

	public:
		Camera() = default;
		Camera(Vector3 position, Vector3 rotation, float fov, UVector2 size)
			: size(size) {}

		inline void Resize(UVector2 size) { this->size = size; }

		void Move();

		glm::mat4 CreateViewMatrix();
		glm::mat4 CreateProjectionMatrix();

	private:
		float fov = 90.0f;;
		float nearPlane = 0.1f;
		float farPlane = 1000.0f;

		float speed = 0.01f;
		float sensitivity = 100.0f;
		bool firstClick = true;

		glm::vec3 position;

		UVector2 size = UVector2(1280, 720);

		glm::vec3 forward = glm::vec3(0.0f, 0.0f, -1.0f);
		glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

	};

}