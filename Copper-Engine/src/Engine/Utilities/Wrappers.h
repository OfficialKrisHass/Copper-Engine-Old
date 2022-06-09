#pragma once

#include "Engine/Core/Core.h"

#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

namespace Copper {

	//-----------------
	//-----Vectors-----
	//-----------------
	class Vector2 {

	public:
		Vector2()					: x(0.0f), y(0.0f) {}
		Vector2(float all)			: x(all), y(all) {}
		Vector2(float x, float y)	: x(x), y(y) {}

		float x;
		float y;

		glm::vec2 ToGLM();

		inline static Vector2 Zero()		{ return Vector2(0.0f); }
		inline static Vector2 One()			{ return Vector2(1.0f); }
		inline static Vector2 MinusOne()	{ return Vector2(-1.0f); }

	};

	class Vector3 {

	public:
		Vector3()							: x(0.0f), y(0.0f), z(0.0f) {}
		Vector3(float all)					: x(all), y(all), z(all) {}
		Vector3(float x, float y, float z)	: x(x), y(y), z(z) {}

		float x;
		float y;
		float z;

		glm::vec3 ToGLM();

		inline static Vector3 Zero()		{ return Vector3(0.0f); }
		inline static Vector3 One()			{ return Vector3(1.0f); }
		inline static Vector3 MinusOne()	{ return Vector3(-1.0f); }

	};

	class Vector4 {

	public:
		Vector4()										: x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
		Vector4(float all)								: x(all), y(all), z(all), w(all) {}
		Vector4(float x, float y, float z)				: x(x), y(y), z(z), w(1.0f) {}
		Vector4(float x, float y, float z, float w)		: x(x), y(y), z(z), w(w) {}

		float x;
		float y;
		float z;
		float w;

		glm::vec4 ToGLM();

		inline static Vector4 Zero()		{ return Vector4(0.0f); }
		inline static Vector4 One()			{ return Vector4(1.0f); }
		inline static Vector4 MinusOne()	{ return Vector4(-1.0f); }

	};

	//----------------
	//-----Colors-----
	//----------------
	class Color {

	public:
		Color()										: r(1.0f), g(0.0f), b(1.0f), a(1.0f) {}
		Color(float all)							: r(all), g(all), b(all), a(1.0f) {}
		Color(float r, float g, float b)			: r(r), g(g), b(b), a(1.0f) {}
		Color(float r, float g, float b, float a)	: r(r), g(g), b(b), a(a) {}

		inline static Color Black() { return Color(0.0f); }
		inline static Color White() { return Color(1.0f); }

		inline static Color Red()	{ return Color(1.0f, 0.0f, 0.0f); }
		inline static Color Green() { return Color(0.0f, 1.0f, 0.0f); }
		inline static Color Blue()	{ return Color(0.0f, 0.0f, 1.0f); }

		float r;
		float g;
		float b;
		float a;

	};

}