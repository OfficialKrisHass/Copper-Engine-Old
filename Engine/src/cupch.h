//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>

#ifdef CU_SYSTEM_WINDOWS
	#include <Windows.h>
#endif

#include <GLM/glm.hpp>

#include <GLM/vec2.hpp>
#include <GLM/vec3.hpp>
#include <GLM/vec4.hpp>

#include <GLM/mat2x2.hpp>
#include <GLM/mat3x3.hpp>
#include <GLM/mat4x4.hpp>

#include <GLM/ext/matrix_transform.hpp>

#include <GLM/gtc/type_ptr.hpp>

#include "Copper/Debug/Log.h"