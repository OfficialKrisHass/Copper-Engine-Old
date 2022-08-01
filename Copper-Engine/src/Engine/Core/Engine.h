#pragma once

#include "Engine/Core/Core.h"
#include "Engine/Core/Window.h"

namespace Copper {

	void InitializeEngine();
	void RunEngine();
	void ExitEngine();

	Window& GetWindow();

}