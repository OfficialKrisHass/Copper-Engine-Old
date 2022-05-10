//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#pragma once

#include "Copper/Core/Core.h"

#include "Copper/Events/Event.h"

namespace Editor {

	class Editor {

	public:
		void OnStart();

		void OnEvent(Copper::Event& e);
		void OnUpdate();

		void OnExit();

	private:
		//

	};

}