//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#pragma once

#include "Copper/Core/Core.h"

#include "Copper/Renderer/Texture.h"

namespace Copper {

	class OpenGLTexture : public Texture {

	public:
		OpenGLTexture(const char* path);
		virtual ~OpenGLTexture();

		virtual void Bind() override;
		virtual void Unbind() override;

	private:
		unsigned int ID;

	};

}