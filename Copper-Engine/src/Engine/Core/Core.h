#pragma once

#include <memory>

#include "Engine/Debug/Log.h"
#include "Engine/Utilities/Wrappers.h"

#define Assert(x, ...) {if(!(x)) {LogError("Assert: {0}", __VA_ARGS__); __debugbreak();} }

#define BindFunction(x) std::bind(&x, this, std::placeholders::_1)

namespace Copper {

	template<typename T> using Unique = std::unique_ptr<T>;

	template<typename T, typename ... Args> constexpr Unique<T> CreateUnique(Args&& ... args) {

		return std::make_unique<T>(std::forward<Args>(args)...);

	}

	template<typename T> using Shared = std::shared_ptr<T>;

	template<typename T, typename ... Args> constexpr Shared<T> CreateShared(Args&& ... args) {

		return std::make_shared<T>(std::forward<Args>(args)...);

	}

}