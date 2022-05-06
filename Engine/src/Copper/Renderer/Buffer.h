//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#pragma once

#include "Copper/Core/Core.h"

namespace Copper {

	class VertexBuffer {

	public:
		static Shared<VertexBuffer> Create(std::vector<float> vertices);

		virtual void Bind() = 0;
		virtual void Unbind() = 0;

	};

	class IndexBuffer {

	public:
		static Shared<IndexBuffer> Create(std::vector<uint32_t> indices);

		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		virtual uint32_t Count() = 0;

	};

}