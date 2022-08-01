#include "cupch.h"
#include "Mesh.h"

namespace Copper {

	Mesh::Mesh(std::vector<float> vertices, std::vector<uint32_t> indices) {

		//

	}

	void Mesh::UpdateMesh() {

		vao = VertexArray::Create();

		Shared<VertexBuffer> vbo = VertexBuffer::Create(vertices);
		Shared<IndexBuffer>  ibo = IndexBuffer::Create(indices);

		vao->AddVertexBuffer(vbo);
		vao->AddIndexBuffer(ibo);

		vbo->Unbind();
		vao->Unbind();

	}

}