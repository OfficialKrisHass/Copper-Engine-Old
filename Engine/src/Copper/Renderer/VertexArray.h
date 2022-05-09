//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//Base VertexArray Header file. Vertex Array is a Core part of the Renderer. Vertex
//Array (or sometimes shortened to VAO) is well an array of Vertex Attributes.
//A Vertex Attribute is like a variable of the Vertex. A vertex can have multiple
//Attributes, one for Position, second for Normals, third for UV coords, Etc.
//And a Vertex Array is like a pointer to these Attributes

#pragma once

#include "Copper/Core/Core.h"

#include "Copper/Renderer/Buffer.h"

namespace Copper {

	//The Base VertexArray Class
	class VertexArray {

	public:
		//A Static Create blah blah, you probably know what this does. And if you don't
		//then check the other headers in the Renderer folder
		static Shared<VertexArray> Create();
		virtual ~VertexArray() = default;

		//Bind and Unbind functions. As with everything else in Rendering, we need to
		//bind something before we can use. and then unbind it when we are done with it
		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		//Functions to Add Vertex and Index Buffers (See Buffer.h file)
		virtual void AddVertexBuffer(const Shared<VertexBuffer> vertexBuffer) = 0;
		virtual void AddIndexBuffer(const Shared<IndexBuffer> indexBuffer) = 0;

		//Get the Index Buffer
		virtual Shared<IndexBuffer> GetIndexBuffer() const = 0;

	};

}