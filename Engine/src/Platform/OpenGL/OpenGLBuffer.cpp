//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//Source file for the OpenGL Implementation of the Vertex and Index Buffer

#include "cupch.h"
#include "OpenGLBuffer.h"

#include <GLAD/glad.h>

namespace Copper {

	//-----------------------
	//-----Vertex Buffer-----
	//-----------------------

	//Constructor
	OpenGLVertexBuffer::OpenGLVertexBuffer(std::vector<float> vertices) {

		//Generates the Buffer itself
		glGenBuffers(1, &ID);

		//Binds the Buffer because we need to tell OpenGL to which Buffer it should load
		//The Data. Then we Load the Data to the Buffer, The First Argument is to signify
		//Which Buffer we are using, in this case Vertex Buffer, then the Second argument
		//Is the size of the Buffer, then the third argument is the data itself (actually
		//It's a pointer to the first element of the Data) and then the Last argument
		//Is the Usage, GL_STATIC_DRAW means that it's stored in one place and we won't
		//be modifying the Data alot, if we were to mdoify it alot we would use GL_DYNAMIC_DRAW
		Bind();
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

	}

	//Destructor to clean the Memory when the Application termiantes
	OpenGLVertexBuffer::~OpenGLVertexBuffer() {

		Log("Deleting Vertex Buffer {0}", ID);
		glDeleteBuffers(1, &ID);

	}

	//Bind Functions
	void OpenGLVertexBuffer::Bind() {

		glBindBuffer(GL_ARRAY_BUFFER, ID);

	}

	//Unbind Function
	void OpenGLVertexBuffer::Unbind() {

		glBindBuffer(GL_ARRAY_BUFFER, 0);

	}

	//----------------------
	//-----Index Buffer-----
	//----------------------

	//Constructor
	OpenGLIndexBuffer::OpenGLIndexBuffer(std::vector<uint32_t> indices) {

		//Set the Indices count to the length of the Indices Array
		this->count = (uint32_t) indices.size();

		//Generates the Buffer
		glGenBuffers(1, &ID);
		
		//The same as with Vertex Buffer, this time we just use a different buffer
		Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

	}

	//Destructor to clean up the Memory
	OpenGLIndexBuffer::~OpenGLIndexBuffer() {

		Log("Deleting Index Buffer {0}", ID);
		glDeleteBuffers(1, &ID);

	}

	//Bind
	void OpenGLIndexBuffer::Bind() {

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);

	}

	//Unbind
	void OpenGLIndexBuffer::Unbind() {

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	}

}