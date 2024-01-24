#include "Level.h"

void Level::Update()
{
	for (size_t i = 0; i < _gameObjects.size(); i++)
	{
		_gameObjects[i]->UpdateComponents();
	}
}