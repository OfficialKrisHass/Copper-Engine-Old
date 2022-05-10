//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#include "cupch.h"
#include "Copper.h"

int main() {

	Copper::Application* app = new Copper::Application();

	app->Initialize();
	app->Run();
	app->Shutdown();

	//std::cin.get();

	delete app;
	return 0;

}