#include "Scene.h"

Scene::Scene()
{
	Game::_scenes.push_back(this);
}

void Scene::Update()
{
	for (size_t i = 0; i < _gameObjects.size(); i++)
	{
		_gameObjects[i]->UpdateComponents();
	}
}

void Scene::AddGameObject(GameObject* gameObjectToAdd)
{
	_gameObjects.push_back(gameObjectToAdd);
}

void Scene::OnLoaded()
{
	//when game.h says its loaded.
}
