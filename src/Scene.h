#pragma once
#include <vector>

#include "Game.h"
#include "GameObject.h"

// Note: Make this so it can't make direct instances.
class Scene
{
public:
	void OnLoaded();
	virtual void Update() = 0;
	void AddGameObject(GameObject* gameObject);

protected:
	void Create();

	const char* _sceneName = "Untitled";
	std::vector<GameObject*> _gameObjects;
};