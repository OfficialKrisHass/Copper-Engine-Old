#pragma once

#include "Engine/Core/Core.h"

namespace Copper {

	class FrameBuffer {

	public:
		static Shared<FrameBuffer> Create(UVector2 size);
		virtual ~FrameBuffer() = default;

		virtual void Resize(UVector2 size) = 0;

		virtual void Bind() = 0;
		virtual void Unbdind() = 0;

		virtual uint32_t GetColorAttachment() = 0;

		virtual uint32_t Width() = 0;
		virtual uint32_t Height() = 0;

	private:
		virtual void Recreate() = 0;

	};

}