#include "Game.h"
#include "Scene.h"
#include "LevelCreator.h"
#include "MenuCreator.h"
#include "Menu.h"

void Game::LoadLevel(Scene* levelToBeLoaded)
{
	std::cout << "RedBrick: Scene Loaded '" << levelToBeLoaded->GetName() << "'" << std::endl;
	_currentScene = levelToBeLoaded;
}

void Game::UpdateLevels()
{
	for (auto scene : _scenes)
	{
		_currentScene->Update();
	}
}

void Game::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
	}
	std::cout << "SDL" << ": Sucessfully initialised" << std::endl;
}

//debug
int BoxCollider::static_number_ = 0;

void Game::Run()
{
	SDL_Event _sdlEvent;

	SDL_Texture* placeholder = Graphics::LoadTexture("img/plain_metal.png");

	Creator* _sceneFactory = new MenuCreator();
	Game::LoadLevel(_sceneFactory->FactoryMethod("Hi"));
	delete _sceneFactory;

	std::cout << Game::_scenes.size() << std::endl;
	std::cout << Game::_currentScene->GetName() << std::endl;

	/*
	Level mainMenu("MainMenu");

	GameObject go1(Vector2D(150, 100), 150);
	Collision* subject = new Collision;
	BoxCollider* observer1 = new BoxCollider(*subject, &go1);
	//Sprite* observer2 = new Sprite(*subject, &go1, placeholder);
	go1.AddComponent(observer1);
	//go1.AddComponent(observer2);
	mainMenu.AddGameObject(&go1);

	subject->CreateMessage("Hello World! :D");
	*/
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
		}
		SDL_RenderClear(Graphics::_renderer);
		Game::UpdateLevels();
		//Graphics here!
		SDL_RenderPresent(Graphics::_renderer);
	}
	std::cout << "Game is shutting down..." << std::endl;
}

void Game::Quit()
{
	SDL_Quit();
	std::cout << "SDL" << ": Cleaned up SDL subsystems" << std::endl;
}

