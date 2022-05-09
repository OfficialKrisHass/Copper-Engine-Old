//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//Header for the OpenGL Implementation of the Vertex Array. Here we give body and
//functionality to the functions that were declared in the base Vertex Array class.

#pragma once

#include "Copper/Renderer/VertexArray.h"

namespace Copper {

	//OpenGL Implementation of the Vertex array class
	class OpenGLVertexArray : public VertexArray {

	public:
		//Constructor and Destructor
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		//Bind and Unbind Functions
		virtual void Bind() override;
		virtual void Unbind() override;

		//Functions to Add the Vertex and Index Buffer
		virtual void AddVertexBuffer(const Shared<VertexBuffer> vertexBuffer) override;
		virtual void AddIndexBuffer(const Shared<IndexBuffer> indexBuffer) override;

		//Function to get the IndexBuffer
		inline virtual Shared<IndexBuffer> GetIndexBuffer() const override { return indexBuffer; }

	private:
		//ID if toe Vertex Array
		unsigned int ID;

		//The IndexBuffer of the Vertex Array
		Shared<IndexBuffer> indexBuffer;

	};

}