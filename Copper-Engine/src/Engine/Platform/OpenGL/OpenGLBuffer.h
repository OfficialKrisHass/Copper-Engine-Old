#pragma once

#include "Engine/Core/Core.h"

#include "Engine/Renderer/Buffer.h"

namespace Copper {

	class OpenGLVertexBuffer : public VertexBuffer {

	public:
		OpenGLVertexBuffer(std::vector<float> vertices);
		virtual ~OpenGLVertexBuffer();

		virtual void Bind() override;
		virtual void Unbind() override;

	private:
		uint32_t ID;

	};

	class OpenGLIndexBuffer : public IndexBuffer {

	public:
		OpenGLIndexBuffer(std::vector<uint32_t> indices);
		virtual ~OpenGLIndexBuffer();

		virtual void Bind() override;
		virtual void Unbind() override;

		inline virtual uint32_t Count() override { return count; }

	private:
		uint32_t ID;
		uint32_t count;

	};

}