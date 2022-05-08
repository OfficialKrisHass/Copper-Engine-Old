//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#include "cupch.h"
#include "Camera.h"

#include "Copper/Core/Application.h"

#include <GLFW/glfw3.h>

#include <GLM/gtx/rotate_vector.hpp>
#include <GLM/gtx/vector_angle.hpp>

namespace Copper {

	Camera::Camera(Shared<Transform> transform, float fov, float nearPlane, float farPlane) : transform(transform), fov(fov), nearPlane(nearPlane), farPlane(farPlane) {}

	glm::mat4 Camera::CreateViewMatrix() {

		glm::mat4 ret(1.0f);

		ret = glm::lookAt(transform->position, transform->position + forward, up);

		return ret;

	}

	glm::mat4 Camera::CreateProjectionMatrix() {

		glm::mat4 ret(1.0f);

		ret = glm::perspective(fov, Application::Get().GetWindow().GetAspectRatio(), nearPlane, farPlane);

		return ret;

	}

	void Camera::Move() {

		GLFWwindow* window = (GLFWwindow*) Application::Get().GetWindow().GetWindowPointer();

		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {

			transform->position += speed * forward;

		}

		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {

			transform->position += speed * -glm::normalize(glm::cross(forward, up));

		}

		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {

			transform->position += speed * -forward;

		}

		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {

			transform->position += speed * glm::normalize(glm::cross(forward, up));

		}

		if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {

			transform->position += speed * up;

		}

		if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {

			transform->position += speed * -up;

		}

		if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
			
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

			if (firstClick) {

				glfwSetCursorPos(window, (Application::Get().GetWindow().GetWidth() / 2), (Application::Get().GetWindow().GetHeight() / 2));

				firstClick = false;

			}

			double mouseX;
			double mouseY;
			
			glfwGetCursorPos(window, &mouseX, &mouseY);

			float rotX =  sensitivity * (float)(mouseY - (Application::Get().GetWindow().GetHeight() / 2)) / Application::Get().GetWindow().GetHeight();
			float rotY =  sensitivity * (float)(mouseX - (Application::Get().GetWindow().GetWidth() / 2)) / Application::Get().GetWindow().GetWidth();

			glm::vec3 newOrientation = glm::rotate(forward, glm::radians(-rotX), glm::normalize(glm::cross(forward, up)));

			if (abs(glm::angle(newOrientation, up) - glm::radians(90.0f)) <= glm::radians(85.0f)) {

				forward = newOrientation;

			}

			forward = glm::rotate(forward, glm::radians(-rotY), up);

			glfwSetCursorPos(window, (Application::Get().GetWindow().GetWidth() / 2), (Application::Get().GetWindow().GetHeight() / 2));

		} else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE) {

			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

			firstClick = true;
		}

	}

}