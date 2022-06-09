#pragma once

#include "Engine/Core/Core.h"

#include "Engine/Events/Event.h"

namespace Copper {

	struct WindowProps {

		uint32_t width = 0;
		uint32_t height = 0;
		std::string title;

	};

	class Window {

	public:
		using EventCallback = std::function<void(Event&)>;

		static Unique<Window> Create(WindowProps data);
		virtual ~Window() = default;

		virtual uint32_t Width() = 0;
		virtual uint32_t Height() = 0;
		virtual float AspectRatio() = 0;

		virtual void SetEventCallback(EventCallback callback) = 0;

		virtual void Update() = 0;

		virtual void Shutdown() = 0;

	private:
		//

	};

}