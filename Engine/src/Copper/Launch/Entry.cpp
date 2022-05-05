//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#include "Copper.h"

//main function to Test if the Project was compiled correctly
/*int main() {

	std::cout << "Hello, World!" << std::endl;
	std::cin.get();

	return 0;

}*/

//Function that Launches the Application, The Main main Function.
int main() {

#ifdef CU_SYSTEM_WINDOWS

	Copper::Application app;

	app.Initialize();
	app.Run();
	app.Shutdown();

	//std::cin.get();
	return 0;

#elif CU_SYSTEM_LINUX

	std::cout << "Copper Engine Currently doesn't support Linux!";
	std::cin.get();

	return 0;

#elif CU_SYSTEM_MAC

	std::cout << "Copper Engine Currently doesn't support MacOS!";
	std::cin.get();

	return 0;

#endif

}