#pragma once

#include "Engine/Core/Core.h"

#include "Engine/Renderer/FrameBuffer.h"

namespace Copper {

	class OpenGLFrameBuffer : public FrameBuffer {

	public:
		OpenGLFrameBuffer(UVector2 size);
		virtual ~OpenGLFrameBuffer();

		virtual void Resize(UVector2 size) override;

		virtual void Bind() override;
		virtual void Unbdind() override;

		virtual uint32_t GetColorAttachment() override { return color; }

		inline virtual uint32_t Width() override { return size.x; }
		inline virtual uint32_t Height() override { return size.y; }

	private:
		uint32_t id;
		uint32_t color;
		uint32_t depth;

		UVector2 size;

		virtual void Recreate() override;

	};

}