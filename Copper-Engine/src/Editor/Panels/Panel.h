#pragma once

#include "Engine/Core/Core.h"

namespace Editor {

	class Panel {

	public:
		Panel(std::string name) : name(name) {}

		std::string name;

		virtual void Render() = 0;

	};

}