#include "cupch.h"

#include "Engine/Entry/EngineLoop.h"

Copper::EngineLoop engineLoop;

int main() {

	engineLoop.Init();
	engineLoop.Run();
	engineLoop.Shutdown();

	//std::cin.get();
	return 0;

}