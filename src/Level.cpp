#include "Level.h"

Level::Level(const char* sceneName)
{
	_sceneName = sceneName;
	Create();
}

void Level::Update()
{
	for (size_t i = 0; i < _gameObjects.size(); i++)
	{
		_gameObjects[i]->UpdateComponents();
	}
}