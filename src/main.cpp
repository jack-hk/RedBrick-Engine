#include <iostream>
#include "Game.h"

// This project uses C++17!

void Run()
{
	SDL_Event _sdlEvent;

	while (Game::_isRunning)
	{

		while (SDL_PollEvent(&_sdlEvent))
		{
			switch (_sdlEvent.type)
			{
			case SDL_QUIT:
				Game::_isRunning = false;
				break;
			}
		}
		SDL_RenderClear(Graphics::_renderer);
		//Graphics here!
		SDL_RenderPresent(Graphics::_renderer);
	}
}

int main(int argc, char* args[])
{
	Game::Init();
	Graphics::CreateWindow("Example", 800, 800, Vector4D(90, 34, 139, SDL_ALPHA_OPAQUE));
	Game::_isRunning = true;

	Run();

	Graphics::DestroyWindow();
	Game::Quit();
	
	return 0;
}