#include "Scene.h"

void Scene::OnLoaded()
{
	std::cout << "RedBrick: Scene Loaded '" <<_sceneName << "'" << std::endl;
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

void Scene::Create()
{
	Game::_scenes.push_back(this);

	//debug: currently changes the level to the newest created instance.
	Game::_currentScene = this;
	Game::_isANewScene = true;
}


