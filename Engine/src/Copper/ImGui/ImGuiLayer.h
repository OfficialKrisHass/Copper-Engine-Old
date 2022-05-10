//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#pragma once

#include "Copper/Core/Core.h"
#include "Copper/Core/Layer.h"

#include "Copper/Events/ApplicationEvent.h"
#include "Copper/Events/KeyEvent.h"
#include "Copper/Events/MouseEvent.h"

namespace Copper {

	class ImGuiLayer : public Layer {

	public:
		ImGuiLayer() : Layer("ImGuiLayer") {}

		virtual void OnAttach() override;

		virtual void OnImGuiRender() override;

		virtual void OnDetach() override;

		void Begin();
		void End();

	private:
		float m_time = 0.0f;

	};

}