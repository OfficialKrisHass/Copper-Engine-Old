//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//Transform Header file. Transform is a component that stores the position, rotation
//and scale of the Object. We also calculate the Model Matrix here since we have
//access to the position, rotation and scale of the Model

#pragma once

#include "Copper/Core/Core.h"

#include <GLM/glm.hpp>

namespace Copper {

	//Transform Class
	class Transform {

	public:
		Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale); //Constructor (obviously)

		//Variables that store the Transform Values
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;

		//Function to Create a Model Matrix
		glm::mat4 CreateModelMatrix();

	private:

	};

}