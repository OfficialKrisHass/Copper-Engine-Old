#pragma once

#include "Engine/Core/Core.h"

#include "Engine/Renderer/Buffer.h"

namespace Copper {

	class VertexArray {

	public:
		static Shared<VertexArray> Create();
		virtual ~VertexArray() = default;

		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		virtual void AddVertexBuffer(Shared<VertexBuffer> vbo) = 0;
		virtual void AddIndexBuffer(Shared<IndexBuffer> ibo) = 0;

		virtual uint32_t VertexCount() = 0;

	private:
		//

	};

}