//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#pragma once

#include <memory>

#define BIT(x) (1 << x)

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