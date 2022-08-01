#pragma once

#include "Engine/Core/Core.h"

#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

namespace Copper {

	//-----------------
	//-----Vector2-----
	//-----------------
	struct Vector2 {

		Vector2()					: x(0.0f), y(0.0f) {}
		Vector2(float all)			: x(all), y(all) {}
		Vector2(float x, float y)	: x(x), y(y) {}

		float x;
		float y;

		operator glm::vec2() const { return glm::vec2(x, y); }

		inline static Vector2 Zero()		{ return Vector2(0.0f); }
		inline static Vector2 One()			{ return Vector2(1.0f); }
		inline static Vector2 MinusOne()	{ return Vector2(-1.0f); }

	};

	//-------------------
	//------Vector3------
	//-------------------
	struct Vector3 {

		Vector3()							: x(0.0f), y(0.0f), z(0.0f) {}
		Vector3(glm::vec3 vec)				: x(vec.x), y(vec.y), z(vec.z) {}
		Vector3(float all)					: x(all), y(all), z(all) {}
		Vector3(float x, float y, float z)	: x(x), y(y), z(z) {}

		float x;
		float y;
		float z;

		operator glm::vec3() const { return glm::vec3(x, y, z); }

		inline Vector3& operator=(const Vector3& other) {

			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
			return *this;

		}
		inline Vector3& operator+=(const Vector3& other) {

			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			return *this;

		}
		inline Vector3& operator+=(const float& other) {

			this->x += other;
			this->y += other;
			this->z += other;
			return *this;

		}
		inline Vector3& operator-=(const Vector3& other) {

			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			return *this;

		}
		inline Vector3& operator-=(const float& other) {

			this->x -= other;
			this->y -= other;
			this->z -= other;
			return *this;

		}
		inline Vector3& operator*=(const Vector3& other) {

			this->x *= other.x;
			this->y *= other.y;
			this->z *= other.z;
			return *this;

		}
		inline Vector3& operator*=(const float& other) {

			this->x *= other;
			this->y *= other;
			this->z *= other;
			return *this;

		}

		inline Vector3& operator++() {

			++this->x;
			++this->y;
			++this->z;
			return *this;

		}
		inline Vector3& operator--() {

			--this->x;
			--this->y;
			--this->z;
			return *this;

		}

		inline Vector3& operator-(const Vector3& other) {

			return Vector3(-x, -y, -z);

		}

		inline static Vector3 Zero()		{ return Vector3(0.0f); }
		inline static Vector3 One()			{ return Vector3(1.0f); }
		inline static Vector3 MinusOne()	{ return Vector3(-1.0f); }

	};

	inline Vector3& operator+(const Vector3& other, float scalar) {

		return Vector3(other.x + scalar, other.y + scalar, other.z + scalar);

	}
	inline Vector3 operator+(const Vector3& other, const Vector3& scalar) {

		return Vector3(other.x + scalar.x, other.y + scalar.y, other.z + scalar.z);

	}
	inline Vector3 operator+(float scalar, const Vector3& other) {

		return Vector3(scalar + other.x, scalar + other.y, scalar + other.z);

	}
	inline Vector3 operator-(const Vector3& other, float scalar) {

		return Vector3(other.x - scalar, other.y - scalar, other.z - scalar);

	}
	inline Vector3 operator-(const Vector3& other, const Vector3& scalar) {

		return Vector3(other.x - scalar.x, other.y - scalar.y, other.z - scalar.z);

	}
	inline Vector3 operator-(float scalar, const Vector3& other) {

		return Vector3(scalar - other.x, scalar - other.y, scalar - other.z);

	}
	inline Vector3 operator*(const Vector3& other, float scalar) {

		return Vector3(other.x * scalar, other.y * scalar, other.z * scalar);

	}
	inline Vector3 operator*(Vector3 const& other, Vector3 const& scalar) {

		return Vector3(other.x * scalar.x, other.y * scalar.y, other.z * scalar.z);

	}
	inline Vector3 operator*(float scalar, const Vector3& other) {

		return Vector3(scalar * other.x, scalar * other.y, scalar * other.z);

	}
	inline Vector3 operator/(const Vector3& other, float scalar) {

		return Vector3(other.x / scalar, other.y / scalar, other.z / scalar);

	}
	inline Vector3 operator/(const Vector3& other, const Vector3& scalar) {

		return Vector3(other.x / scalar.x, other.y / scalar.y, other.z / scalar.z);

	}
	inline Vector3 operator/(float scalar, const Vector3& other) {

		return Vector3(scalar / other.x, scalar / other.y, scalar / other.z);

	}

	inline std::ostream& operator<<(std::ostream& os, const Vector3& vec) {

		return os << "X: " << vec.x << ", Y: " << vec.y << ", Z: " << vec.z;

	}

	//-------------------
	//------Vector4------
	//-------------------
	struct Vector4 {

		Vector4()										: x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
		Vector4(float all)								: x(all), y(all), z(all), w(all) {}
		Vector4(float x, float y, float z)				: x(x), y(y), z(z), w(1.0f) {}
		Vector4(float x, float y, float z, float w)		: x(x), y(y), z(z), w(w) {}

		float x;
		float y;
		float z;
		float w;

		operator glm::vec4() const { return glm::vec4(x, y, z, w); }

		inline static Vector4 Zero()		{ return Vector4(0.0f); }
		inline static Vector4 One()			{ return Vector4(1.0f); }
		inline static Vector4 MinusOne()	{ return Vector4(-1.0f); }

	};

	struct UVector2 {

		UVector2() : x(0), y(0) {}
		UVector2(uint32_t all) : x(all), y(all) {}
		UVector2(uint32_t x, uint32_t y) : x(x), y(y) {}

		uint32_t x;
		uint32_t y;

		inline static UVector2 Zero() { return UVector2(0); }
		inline static UVector2 One() { return UVector2(1); }
		inline static UVector2 MinusOne() { return UVector2(-1); }

	};

	//----------------
	//-----Colors-----
	//----------------
	struct Color {

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