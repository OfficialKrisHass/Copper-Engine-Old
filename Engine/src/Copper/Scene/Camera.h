//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//This is the Camera Header. The Camera is a very important thing, basically the most
//important part of the renderer. But contrary to the popular belief, Camera doesn't
//Really exist. It's not like some sort of OpenGL function. The Camera only stores
//Position and Rotation of the camera and this is then used to calculate matrices
//That makes it look 3D.

#pragma once

#include "Copper/Core/Core.h"

#include "Copper/Scene/Transform.h"

namespace Copper {

	//The Camera class
	//NOTE: This Camera should probably work like other things in the Renderer folder
	//Because when we are using OpenGL we are going to use glm for the matrices and
	//vectors, but glm works only with OpenGL so this probably won't work with DirectX
	class Camera {

	public:
		//Constructor that takes a transform and can take other variables but doesn't have to
		Camera(Shared<Transform> transform, float fov = 90.0f, float nearPlane = 0.01f, float farPlane = 1000.0f);

		//The Camera Transform
		Shared<Transform> transform;

		//Functions to Create the View and Projection Matrices
		glm::mat4 CreateViewMatrix();
		glm::mat4 CreateProjectionMatrix();

		//Prototype Move function that allows us to move around in the scene
		//TODO: This function should only be inside the Scene Camera
		void Move();

	private:
		//The Camera settings, important for creating matrices
		float fov;
		float nearPlane;
		float farPlane;

		//Variables for movement
		bool firstClick = true;
		float speed = 0.1f;
		float sensitivity = 100.0f;

		//Vectors that signify the rotation of the Camera
		//TODO: Move these vectors (and also other directionaly vectors) To the
		//Transform class, Every object should be available to get their directional
		//Vectors, so this should be stored and calculate in Transform
		glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
		glm::vec3 forward = glm::vec3(0.0f, 0.0f, -1.0f);

	};

}