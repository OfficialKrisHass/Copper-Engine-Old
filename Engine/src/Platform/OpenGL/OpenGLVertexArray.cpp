//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//Source file for the OpenGL Implementation of the Vertex Array

#include "cupch.h"
#include "OpenGLVertexArray.h"

#include <GLAD/glad.h>

namespace Copper {

	static GLenum DataTypeToOpenGL(DataType type) {

		switch (type) {

		case DataType::Float:	return GL_FLOAT;
		case DataType::Float2:	return GL_FLOAT;
		case DataType::Float3:  return GL_FLOAT;
		case DataType::Float4:  return GL_FLOAT;
		case DataType::Mat3:	return GL_FLOAT;
		case DataType::Mat4:	return GL_FLOAT;
		case DataType::Int:		return GL_INT;
		case DataType::Int2:	return GL_INT;
		case DataType::Int3:	return GL_INT;
		case DataType::Int4:	return GL_INT;
		case DataType::Bool:	return GL_BOOL;


		}

		LogError("Unkown DataType!");
		return 0;

	}

	//Constructor that just simply generates the Vertex Array
	OpenGLVertexArray::OpenGLVertexArray() {

		glGenVertexArrays(1, &ID);

	}

	//Constructor to clean up the memory
	OpenGLVertexArray::~OpenGLVertexArray() {

		Log("Deleting Vertex Array {0}", ID);

		glDeleteVertexArrays(1, &ID);

	}

	//Bind
	void OpenGLVertexArray::Bind() {

		glBindVertexArray(ID);

	}

	//Unbind
	void OpenGLVertexArray::Unbind() {

		glBindVertexArray(0);

	}

	//Function to add a Vertex Buffer to the Vertex Array
	void OpenGLVertexArray::AddVertexBuffer(const Shared<VertexBuffer> vertexBuffer) {

		//Bind the Vertex Array
		Bind();

		uint32_t index = 0;
		for (const Attribute& attrib : vertexBuffer->GetLayout()) {

			//After that we also need to enable this Vertex Attribute
			glEnableVertexAttribArray(index);

			//Sets up the Vertex Attribute to let it know how it should read the Vertex Data.
			//An Vertex Attribute is a part of the Vertex Data, A Vertex might have a position
			//(attribute 0) and a UV coord (attribute 1) and more. In Order for the GPU to know
			//what is the position of the Vertex or what is the Color of the Vertex we need to let
			//it know how the Atributes are stored. The first Argument is what Attribute we are
			//Working with, the second Argument is how many dimensions does this attribute have
			//(position might have vec3 so 3 dimensions, UV Coords Vec2 so only 2 dimensions. etc)
			//The Third argument is of what type are these 3 numbers, The Fourth Argument is if
			//The Values are normalized, the Fifth Argument is the Stride of Attribute, The Stride
			//is basically how much space is between the first number of the first part of the
			//attribute and the first number of the second part of the attribute. And then the
			//Last argument is the Offset of the first attribute.
			//
			//Example:
			//
			//Notation:
			//P0x - x component of position of vertex 0      (gl_VertexID == 0)
			//P3z - z component of position of vertex 3      (gl_VertexID == 3)
			//C0u - u component of texture coord of vertex 0 (gl_VertexID == 0)
			//C8v - v component of texture coord of vertex 8 (gl_VertexID == 8)
			//000 - empty space(one uint8_t)
			//
			//			offset of UV coord                stride of UV coord
			//			|<------------------------->|<----------------------------->|
			//			|                           |                               |
			//buffer : |000|000|000|P0x|P0y|P0z|000|C0u|C0v|000|000|P1x|P1y|P1z|000|C1u|C1v|...
			//		   |           |                               |
			//		   | offset of |                               |
			//		   | position  |      stride of position       |
			//		   |<--------->|<----------------------------->|
			glVertexAttribPointer(index, attrib.GetDimensions(), DataTypeToOpenGL(attrib.type), GL_FALSE, vertexBuffer->GetLayout().GetStride(), (void*) attrib.offset);

			index++;

		}

	}

	void OpenGLVertexArray::AddIndexBuffer(const Shared<IndexBuffer> indexBuffer) {

		//Bind the Vertex Array first so that when we bind the index buffer it will
		//automatically assign the Index Buffer to the Vertex Array
		Bind();
		indexBuffer->Bind();

		//Set the class's index Buffer to this one
		this->indexBuffer = indexBuffer;

	}

}