//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#pragma once

#include "Copper/Core/Core.h"

#include "Copper/Renderer/VertexArray.h"
#include "Copper/Scene/Transform.h"

namespace Copper {

	class Mesh {

	public:
		Mesh(Shared<Transform> transform, Shared<VertexArray> vao) : transform(transform), vao(vao) {}

		Shared<Transform> transform;

		inline void BindVAO()   { vao->Bind(); }
		inline void UnbindVAO() { vao->Unbind(); }

		inline uint32_t GetVertexCount() { return vao->GetIndexBuffer()->Count(); }

	private:
		Shared<VertexArray> vao;

	};

}