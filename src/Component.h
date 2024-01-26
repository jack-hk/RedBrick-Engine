#pragma once

#include "IObserver.h"

class GameObject;
class Component : public IObserver
{
public:
	GameObject* _gameObject;

	Component(GameObject* gameObject);

private:
	bool _isEnabled = true;
};