#pragma once

#include "Engine/Core/Core.h"

#include "Engine/Scene/Components/Transform.h"
#include "Engine/Scene/Components/Component.h"
#include "Engine/Renderer/VertexArray.h"

namespace Copper {

	class Mesh : public Component {

	public:
		Mesh() = default;
		Mesh(std::vector<float> vertices, std::vector<uint32_t> indices);

		inline Shared<VertexArray> GetVAO() { return vao; }

		std::vector<float> vertices;
		std::vector <uint32_t> indices;

		void UpdateMesh();

	private:
		Shared<VertexArray> vao;

	};

}