//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#pragma once

#include "Copper/Core/Core.h"

#include "Copper/Scene/Transform.h"

namespace Copper {

	class Camera {

	public:
		Camera(Shared<Transform> transform, float fov = 90.0f, float nearPlane = 0.01f, float farPlane = 1000.0f);

		Shared<Transform> transform;

		glm::mat4 CreateViewMatrix();
		glm::mat4 CreateProjectionMatrix();

		void Move();

	private:
		float fov;
		float nearPlane;
		float farPlane;

		bool firstClick = true;

		float speed = 0.1f;
		float sensitivity = 100.0f;

		glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
		glm::vec3 forward = glm::vec3(0.0f, 0.0f, -1.0f);

	};

}