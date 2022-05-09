//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//Header File for the OpenGL Implementation of the Vertex and Index Buffers. Here we
//Give the functions that were declared in the Base Buffer class an actual body.

#pragma once

#include "Copper/Core/Core.h"
#include "Copper/Renderer/Buffer.h"

namespace Copper {

	//OpenGL Vertex Buffer Implementation class
	class OpenGLVertexBuffer : public VertexBuffer {

	public:
		//Constructor that takes the Vertex Data, and a Destructor
		OpenGLVertexBuffer(std::vector<float> vertices);
		virtual ~OpenGLVertexBuffer();

		//Functions to Bind and Unbind the Vertex Buffer
		virtual void Bind() override;
		virtual void Unbind() override;

		virtual void SetLayout(const BufferLayout layout) override { this->layout = layout; }
		virtual BufferLayout GetLayout() override { return layout; }

	private:
		//ID and Layout of the Vertex Buffer
		unsigned int ID;
		BufferLayout layout;

	};

	//OpenGL Index Buffer Implementation class
	class OpenGLIndexBuffer : public IndexBuffer {

	public:
		//Constructor that takes the Indices, and a destructor
		OpenGLIndexBuffer(std::vector<uint32_t> indices);
		virtual ~OpenGLIndexBuffer();

		//Bind and Unbind functions, blah blah, you know what this does, it's in the name
		virtual void Bind() override;
		virtual void Unbind() override;

		//Function to get the Count of Indices
		inline virtual uint32_t Count() override { return count; }

	private:
		//ID and amount of Indices
		unsigned int ID;
		uint32_t count;

	};

}