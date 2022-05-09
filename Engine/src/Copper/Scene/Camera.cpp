//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//The Camera Source File. Here we mainly calculate the vertices and the Movement.

#include "cupch.h"
#include "Camera.h"

#include "Copper/Core/Application.h"

#include <GLFW/glfw3.h>

#include <GLM/gtx/rotate_vector.hpp>
#include <GLM/gtx/vector_angle.hpp>

namespace Copper {

	//Constructor that sets the important Camera Settings
	Camera::Camera(Shared<Transform> transform, float fov, float nearPlane, float farPlane) : transform(transform), fov(fov), nearPlane(nearPlane), farPlane(farPlane) {}

	//Function that creates the View Matrix. The View Matrix is a matrix that is used
	//to Transform vertices from 3D Space (xyz coordinates) to View Space, this means
	//It cuts everything that is outside the Cameras view.
	glm::mat4 Camera::CreateViewMatrix() {

		//Create an Empty Matrix and set it's identity to 1.0f
		glm::mat4 ret(1.0f);

		//Use the GLM LookAt function that basically creates the View Matrix. The
		//First Argument is the centre/position of the Camera, The Second argument
		//is the Eye/Where is the Camera looking and the Third argument is the cameras
		//Up Direction (this is only changed based on yRotation)
		ret = glm::lookAt(transform->position, transform->position + forward, up);

		//Return the newly created View Matrix
		return ret;

	}

	//Function that Creates the Projection Matrix. The Projection Matrix is probably
	//The most interesting Matrix, It makes it look 3D. When something is far away
	//It looks smaller, and mainly, it stretches things so that they stay the same
	//shape when the Window is resized (so a square will always look like a square
	//No matter how much you resize the Window)
	glm::mat4 Camera::CreateProjectionMatrix() {

		//Again, creates an Empty matrix and set it's identity to 1.0f
		glm::mat4 ret(1.0f);

		//Here we also use a GLM function that also creates the Perspective (far away
		//= smaller) Projection Matrix . The First argument is the FOV (Fiel Of View
		//which is basically how much to the sides can the camera see, the Second
		//argument is the Aspect Ratio of the Window which we calculate by dividing
		//the Width by the Height of the window, the third argument is the near plane
		//Which is How far away from the camera starts the vision of the camera, and 
		//The Last argument is the Far Plane which is basically how far away from the
		//Camera can we see.
		ret = glm::perspective(fov, Application::Get().GetWindow().GetAspectRatio(), nearPlane, farPlane);

		//Return the new Projection Matrix
		return ret;

	}

	//The Camera Move function. This lets us Move and Look around with the Camera
	void Camera::Move() {

		//We Get the GLFWwindow pointer to the window we are rendering to
		GLFWwindow* window = (GLFWwindow*) Application::Get().GetWindow().GetWindowPointer();

		//---------------------
		//-----Key Presses-----
		//---------------------

		//If we press W Move Forward
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {

			transform->position += speed * forward;

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

		//---------------------
		//-----Look Around-----
		//---------------------

		//If we are holding the Left Mouse Button
		if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
			
			//Hide the Cursor
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

			//Check if it's the first click to prevent the Camera from jumping
			if (firstClick) {

				//Set the Cursor into the Middle of the screen
				glfwSetCursorPos(window, (Application::Get().GetWindow().GetWidth() / 2), (Application::Get().GetWindow().GetHeight() / 2));

				//Set FirstClick to false
				firstClick = false;

			}

			//Position of the mouse in the Window
			double mouseX;
			double mouseY;
			
			//Get the Position of the mouse and store it in the previous variables
			glfwGetCursorPos(window, &mouseX, &mouseY);

			//Calculate The new Rotation of the Camera by multiplying sensitivity by the position of the mouse minus the centre of the screen
			float rotX =  sensitivity * (float)(mouseY - (Application::Get().GetWindow().GetHeight() / 2)) / Application::Get().GetWindow().GetHeight();
			float rotY =  sensitivity * (float)(mouseX - (Application::Get().GetWindow().GetWidth() / 2)) / Application::Get().GetWindow().GetWidth();

			//Set the NewOrientation of the Camera
			glm::vec3 newOrientation = glm::rotate(forward, glm::radians(-rotX), glm::normalize(glm::cross(forward, up)));

			//Clamp The rotation so that we can look only 90 degrees up and down
			if (abs(glm::angle(newOrientation, up) - glm::radians(90.0f)) <= glm::radians(85.0f)) {

				forward = newOrientation;

			}

			//Rotate the forward to the sides
			forward = glm::rotate(forward, glm::radians(-rotY), up);

			//Set the Cursor Position to the Middle
			glfwSetCursorPos(window, (Application::Get().GetWindow().GetWidth() / 2), (Application::Get().GetWindow().GetHeight() / 2));

		} else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE) { //If we stopped holding the Left Mouse Button

			//Show the cursor
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

			//And set the firstClick to true
			firstClick = true;
		}

	}

}