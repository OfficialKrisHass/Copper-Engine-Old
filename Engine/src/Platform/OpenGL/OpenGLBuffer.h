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

	class OpenGLVertexBuffer : public VertexBuffer {

	public:
		OpenGLVertexBuffer(std::vector<float> vertices);

		virtual void Bind() override;
		virtual void Unbind() override;

	private:
		unsigned int ID;

	};

	class OpenGLIndexBuffer : public IndexBuffer {

	public:
		OpenGLIndexBuffer(std::vector<uint32_t> indices);

		virtual void Bind() override;
		virtual void Unbind() override;

		virtual uint32_t Count() override;

	private:
		unsigned int ID;
		uint32_t count;

	};

}