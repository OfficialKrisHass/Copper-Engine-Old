//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#pragma once

#include "Copper/Core/Core.h"

#include "Copper/Events/Event.h"

namespace Copper {

	class Layer {

	public:
		Layer(const std::string name = "Layer") : name(name) {}
		virtual ~Layer() = default;

		virtual void OnAttach() = 0;
		
		virtual void OnUpdate() {}
		virtual void OnImGuiRender() = 0;
		virtual void OnEvent(Event& event) {}

		virtual void OnDetach() = 0;

	protected:
		std::string name;

	};

}