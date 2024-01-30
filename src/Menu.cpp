#include "Menu.h"

Menu::Menu(const char* sceneName)
{
	_sceneName = sceneName;
	Game::_scenes.push_back(this);
}

void Menu::Update()
{
	for (size_t i = 0; i < _gameObjects.size(); i++)
	{
		_gameObjects[i]->UpdateComponents();
	}
}
