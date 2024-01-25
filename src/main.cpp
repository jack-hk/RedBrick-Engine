#include "Game.h"
#include "GameObject.h"
#include "Input.h"
#include "Level.h"
#include "Menu.h"

// This project uses C++20!

void Run()
{
	SDL_Event _sdlEvent;

	SDL_Texture* placeholder = Graphics::LoadTexture("img/plain_metal.png");

	Menu mainMenu("MainMenu");
	GameObject go1(Vector2D(150, 100), 150);
	go1.AddComponent(new Sprite(&go1, placeholder));
	mainMenu.AddGameObject(&go1);

	while (Game::_isRunning)
	{
		Input::Update();
		while (SDL_PollEvent(&_sdlEvent))
		{
			switch (_sdlEvent.type)
			{
			case SDL_QUIT:
				Game::_isRunning = false;
				break;
			}

			//Debug, Input (GetKey, GetKeyDown, GetKeyUp)
			if (Input::GetKeyDown(SDL_SCANCODE_A))
			{
				std::cout << "DEBUG: A pressed" << std::endl;
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
	Input::Init();
	Graphics::CreateWindow("Example", 800, 800, Vector4D(90, 34, 139, SDL_ALPHA_OPAQUE));
	Game::_isRunning = true;

	Run();

	Graphics::DestroyWindow();
	Input::Clean();
	Game::Quit();
	
	return 0;
}