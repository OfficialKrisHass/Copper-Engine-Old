#pragma once

#include "Engine/Core/Core.h"

namespace Copper {

	class Tag {

	public:
		Tag() = default;
		Tag(const std::string& name) : name(name) {}

		std::string name;

	};

}