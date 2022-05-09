//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//The Mesh Header file. Mesh is a Component that stores the Vertex Data itself
//It is basically the Model. At least now we also give it a Transform so that we can
//easily make a Model Matrix from this mesh too

#pragma once

#include "Copper/Core/Core.h"

#include "Copper/Renderer/VertexArray.h"
#include "Copper/Renderer/Texture.h"

#include "Copper/Scene/Transform.h"

namespace Copper {

	//Mesh class
	class Mesh {

	public:
		//Constructor that just sets the variables
		Mesh(Shared<Transform> transform, Shared<VertexArray> vao, Shared<Texture> texture) : transform(transform), vao(vao), texture(texture) {}

		//The Mesh's Transform
		Shared<Transform> transform;

		//Bind and Unbind the Mesh's Vertex Array
		inline void BindVAO()   { vao->Bind(); }
		inline void UnbindVAO() { vao->Unbind(); }

		inline void BindTexture() { texture->Bind(); }
		inline void UnbindTexture() { texture->Unbind(); }

		//Get the Vertex Count of the Mesh
		inline uint32_t GetVertexCount() { return vao->GetIndexBuffer()->Count(); }

	private:
		Shared<VertexArray> vao;
		Shared<Texture> texture;

	};

}