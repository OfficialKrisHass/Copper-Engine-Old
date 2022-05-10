//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#include "cupch.h"
#include "Editor.h"

namespace Editor {

	//Editor Opened
	void Editor::OnStart() {

		EditorLogTrace("\n-------Editor Initialization-------");

		EditorLog("Editor Successfully Initialized!");
		EditorLogTrace("-----------------------------------");

	}

	//Editor Events
	void Editor::OnEvent(Copper::Event& event) {

		//EditorLog(event);

	}

	//Editor Run Loop
	void Editor::OnUpdate() {

		//

	}

	//Editor Closed
	void Editor::OnExit() {

		EditorLog("Deleting Editor");

	}

}