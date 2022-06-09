#include "cupch.h"
#include "Camera.h"

#include "Engine/Entry/EngineLoop.h"

#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>

namespace Copper {

	glm::mat4 Camera::CreateViewMatrix() {

		glm::mat4 view(1.0f);

		view = glm::lookAt(position.ToGLM(), position.ToGLM() + forward.ToGLM(), up.ToGLM());

		return view;

	}

	glm::mat4 Camera::CreateProjectionMatrix() {

		glm::mat4 projection(1.0f);

		projection = glm::perspective(fov, EngineLoop::Get().GetWindow().AspectRatio(), nearPlane, farPlane);

		return projection;

	}

}