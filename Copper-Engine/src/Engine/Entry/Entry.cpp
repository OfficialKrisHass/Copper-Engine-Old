#include "cupch.h"
#include "Engine/Core/Engine.h"

int main() {

	Copper::InitializeEngine();
	Copper::RunEngine();
	Copper::ExitEngine();

	//std::cin.get();
	return 0;

}