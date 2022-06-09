#pragma once

#include "Engine/Core/Core.h"

namespace Copper {

	class VertexBuffer {

	public:
		static Shared<VertexBuffer> Create(std::vector<float> vertices);
		virtual ~VertexBuffer() = default;

		virtual void Bind() = 0;
		virtual void Unbind() = 0;

	private:
		//

	};

	class IndexBuffer {

	public:
		static Shared<IndexBuffer> Create(std::vector<uint32_t> indices);
		virtual ~IndexBuffer() = default;

		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		virtual uint32_t Count() = 0;

	private:
		//

	};

}