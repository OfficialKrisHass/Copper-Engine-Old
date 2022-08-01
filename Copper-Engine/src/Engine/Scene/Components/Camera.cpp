#include "cupch.h"
#include "Camera.h"

#include "Engine/Core/Engine.h"

#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <GLM/gtx/rotate_vector.hpp>
#include <GLM/gtx/vector_angle.hpp>

#include <GLFW/glfw3.h>

namespace Copper {

	glm::mat4 Camera::CreateViewMatrix() {

		glm::mat4 view(1.0f);

		view = glm::lookAt((glm::vec3) transform->position, (glm::vec3) transform->position + forward, up);

		return view;

	}

	glm::mat4 Camera::CreateProjectionMatrix() {

		glm::mat4 projection(1.0f);

		projection = glm::perspective(fov, static_cast<float>(size.x) / size.y, nearPlane, farPlane);

		return projection;

	}

	void Camera::Move() {

		GLFWwindow* window = (GLFWwindow*) GetWindow().GetWindowPtr();

		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {

			transform->position += forward * speed;

		}

		//If we press A Move Left
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {

			transform->position += speed * -glm::normalize(glm::cross(forward, up));

		}

		//If we press S move backwards
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {

			transform->position += speed * -forward;

		}

		//If we press D Move Right
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {

			transform->position += speed * glm::normalize(glm::cross(forward, up));

		}

		//If we press Space move Up
		if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {

			transform->position += speed * up;

		}

		//If we press Shift move Down
		if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {

			transform->position += speed * -up;

		}

		//if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {

		//	//Hide the Cursor
		//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		//	//Check if it's the first click to prevent the Camera from jumping
		//	if (firstClick) {

		//		//Set the Cursor into the Middle of the screen
		//		glfwSetCursorPos(window, (size.x / 2), (size.y / 2));

		//		//Set FirstClick to false
		//		firstClick = false;

		//	}

		//	//Position of the mouse in the Window
		//	double mouseX;
		//	double mouseY;

		//	//Get the Position of the mouse and store it in the previous variables
		//	glfwGetCursorPos(window, &mouseX, &mouseY);

		//	//Calculate The new Rotation of the Camera by multiplying sensitivity by the position of the mouse minus the centre of the screen
		//	float rotX = sensitivity * (float) (mouseY - (size.y / 2)) / size.y;
		//	float rotY = sensitivity * (float) (mouseX - (size.x / 2)) / size.x;

		//	//Set the NewOrientation of the Camera
		//	glm::vec3 newOrientation = glm::rotate(forward, glm::radians(-rotX), glm::normalize(glm::cross(forward, up)));

		//	//Clamp The rotation so that we can look only 90 degrees up and down
		//	if (abs(glm::angle(newOrientation, up) - glm::radians(90.0f)) <= glm::radians(85.0f)) {

		//		forward = newOrientation;

		//	}

		//	//Rotate the forward to the sides
		//	forward = glm::rotate(forward, glm::radians(-rotY), up);

		//	//Set the Cursor Position to the Middle
		//	glfwSetCursorPos(window, (size.x / 2), (size.y / 2));

		//} else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE) { //If we stopped holding the Left Mouse Button

		//	//Show the cursor
		//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

		//	//And set the firstClick to true
		//	firstClick = true;
		//}

	}

}