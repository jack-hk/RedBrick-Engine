#pragma once
#include <vector>

#include "Game.h"
#include "GameObject.h"

class Scene
{
public:
	Scene();
	virtual void Update() = 0;
	void AddGameObject(GameObject* gameObject);

	void OnLoaded();

protected:
	std::vector<GameObject*> _gameObjects;
};