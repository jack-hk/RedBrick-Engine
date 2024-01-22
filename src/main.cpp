#include "Game.h"
#include "GameObject.h"
#include "Level.h"


// This project uses C++17!

void Run()
{
	SDL_Event _sdlEvent;

	Level level;
	GameObject go1(Vector2D(80, 100), 80);
	level.AddGameObject(&go1);

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
		Game::UpdateLevels();
		//Graphics here!
		SDL_RenderPresent(Graphics::_renderer);
	}
	std::cout << "Game is shutting down..." << std::endl;
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