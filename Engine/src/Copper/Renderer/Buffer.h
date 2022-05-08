//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//This is the header file where we declare Base casses for our Buffers. There are Two
//types of buffers, Vertex Buffer that stores the Vertex Data (position, normal, UV, etc)
//And Index Buffer that stores the Indices, or in other words, In what order we want
//to Connect the Vertices

#pragma once

#include "Copper/Core/Core.h"

namespace Copper {

	//VertexBuffer Class, as mentioned previously Vertex Buffer stores the Vertex data
	class VertexBuffer {

	public:
		//A Create function and a default Destructor
		static Shared<VertexBuffer> Create(std::vector<float> vertices);
		virtual ~VertexBuffer() = default;

		//Functions used to Bind the Vertex Buffer. Before we can use the VBO we need
		//to Bind it and after we are done using it we can Unbind it.
		virtual void Bind() = 0;
		virtual void Unbind() = 0;

	};

	class IndexBuffer {

	public:
		//Again, a Static Create function and a Default Destructor
		static Shared<IndexBuffer> Create(std::vector<uint32_t> indices);
		virtual ~IndexBuffer() = default;

		//Same case as IndexBuffer. Before we can use it we need to Bind the IBO(or EBO)
		//And Unbind it when we are done using it
		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		//Returns the Indices Count
		virtual uint32_t Count() = 0;

	};

}