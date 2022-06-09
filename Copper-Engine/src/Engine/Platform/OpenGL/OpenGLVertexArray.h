#pragma once

#include "Engine/Core/Core.h"

#include "Engine/Renderer/VertexArray.h"

namespace Copper {

	class OpenGLVertexArray : public VertexArray {

	public:
		OpenGLVertexArray();

		virtual void Bind() override;
		virtual void Unbind() override;

		virtual void AddVertexBuffer(Shared<VertexBuffer> vbo) override;
		virtual void AddIndexBuffer(Shared<IndexBuffer> ibo) override;

		virtual uint32_t VertexCount() override { return ibo->Count(); }

	private:
		uint32_t ID;
		
		Shared<IndexBuffer> ibo;

	};

}