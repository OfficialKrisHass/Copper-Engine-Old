#include "cupch.h"
#include "Wrappers.h"

#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

namespace Copper {

	glm::vec2 Vector2::ToGLM() { return glm::vec2(x, y); }
	glm::vec3 Vector3::ToGLM() { return glm::vec3(x, y, z); }
	glm::vec4 Vector4::ToGLM() { return glm::vec4(x, y, z, w); }

}