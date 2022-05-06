//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#pragma once

#include "Copper/Renderer/Renderer.h"

namespace Copper {

	class OpenGLRenderer : public Renderer {

	public:
		virtual void Initialize() override;
		virtual void ClearColor(float r, float g, float b) override;

		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
		inline virtual void SetShader(Shared<Shader> shader) override { this->shader = shader; }

		virtual void Render(const Shared<VertexArray>& vao) override;

	private:
		Shared<Shader> shader;

	};

}