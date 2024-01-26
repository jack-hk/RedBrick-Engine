#include "Game.h"

// This project uses C++20!

int main(int argc, char* args[])
{
	Game::Init();
	Input::Init();
	Graphics::CreateWindow("Example", 800, 800, Vector4D(90, 34, 139, SDL_ALPHA_OPAQUE));
	Game::_isRunning = true;

	Game::Run();

	Graphics::DestroyWindow();
	Input::Clean();
	Game::Quit();
	
	return 0;
}