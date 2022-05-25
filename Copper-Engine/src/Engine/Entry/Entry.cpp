#include <iostream>

#include "Engine/Entry/EngineLoop.h"

#include "Engine/Debug/Log.h"

Copper::EngineLoop engineLoop;

int main() {

	engineLoop.Init();
	engineLoop.Run();
	engineLoop.Shutdown();

	std::cin.get();
	return 0;

}