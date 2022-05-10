//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#pragma once

#include <memory>

#include "Copper/Debug/Log.h"

#define BIT(x) (1 << x)

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

namespace Copper {

	//Wraper for std::unique_ptr. Let's say we want to point
	//to a float. If we use Unique Pointer then there can
	//be only one single Pointer that can point to this
	//float. Useful for when something should only exist once
	template<typename T> using Unique = std::unique_ptr<T>;

	template<typename T, typename ... Args> constexpr Unique<T> CreateUnique(Args&& ... args) {

		return std::make_unique<T>(std::forward<Args>(args)...);

	}

	//Wrapper for std::shared_ptr. Let's use the same scenario
	//we have a float that we want to point to. If we use Shared
	//Pointer, then there can be multiple pointer pointing towards
	//the same variable. We can also get how many pointers point
	//to the same variable.
	template<typename T> using Shared = std::shared_ptr<T>;

	template<typename T, typename ... Args> constexpr Shared<T> CreateShared(Args&& ... args) {

		return std::make_shared<T>(std::forward<Args>(args)...);

	}

}