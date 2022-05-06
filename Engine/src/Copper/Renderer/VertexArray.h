//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#pragma once

#include "Copper/Core/Core.h"

#include "Copper/Renderer/Buffer.h"

namespace Copper {

	class VertexArray {

	public:
		static Shared<VertexArray> Create();

		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		virtual void AddVertexBuffer(const Shared<VertexBuffer> vertexBuffer) = 0;
		virtual void AddIndexBuffer(const Shared<IndexBuffer> indexBuffer) = 0;

		virtual Shared<IndexBuffer> GetIndexBuffer() const = 0;

	};

}