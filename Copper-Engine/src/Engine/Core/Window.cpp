#include "cupch.h"
#include "Window.h"

#include "Engine/Platform/Windows/WindowsWindow.h"

namespace Copper {

	Unique<Window> Window::Create(WindowProps data) {

		return CreateUnique<WindowsWindow>(data);

	}

}