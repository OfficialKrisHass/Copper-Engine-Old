//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#pragma once

#include "Copper/Renderer/VertexArray.h"

namespace Copper {

	class OpenGLVertexArray : public VertexArray {

	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		virtual void Bind() override;
		virtual void Unbind() override;

		virtual void AddVertexBuffer(const Shared<VertexBuffer> vertexBuffer) override;
		virtual void AddIndexBuffer(const Shared<IndexBuffer> indexBuffer) override;

		inline virtual Shared<IndexBuffer> GetIndexBuffer() const override { return indexBuffer; }

	private:
		unsigned int ID;

		Shared<IndexBuffer> indexBuffer;

	};

}