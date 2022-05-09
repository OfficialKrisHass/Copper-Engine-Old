//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//Transform Source File. 

#include "cupch.h"
#include "Transform.h"

namespace Copper {

	//Set the constructor to set the Transform variables to what was given through the constructor
	Transform::Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) : position(position), rotation(rotation), scale(scale) {}

	//Function that Creates the Model Matrix. The Model Matrix is a matrix that
	//stores the position of the Object in 3D space and is used to calculate
	//where on the screen should the object be based on where it is in 3D space
	glm::mat4 Transform::CreateModelMatrix() {

		//Create an empty matrix and set it's identity to 1.0f
		glm::mat4 ret(1.0f);

		//Translate/Move the Matrix based on the Position
		ret = glm::translate(ret, position);
		
		//Rotate the Matrix based on the Rotation
		ret = glm::rotate(ret, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		ret = glm::rotate(ret, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		ret = glm::rotate(ret, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

		//Scale the Matrix based on the Scale
		ret = glm::scale(ret, scale);

		//Return the transformed Model Matrix
		return ret;

	}

}