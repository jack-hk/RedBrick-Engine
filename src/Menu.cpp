#include "Menu.h"

//de
#include <iostream>

void Menu::Update()
{
	for (size_t i = 0; i < _gameObjects.size(); i++)
	{
		_gameObjects[i]->UpdateComponents();

		if (_gameObjects[i]->GetComponent<UIElement>() != nullptr)
		{
			_UIElements.push_back(_gameObjects[i]->GetComponent<UIElement>());
			
		}
		std::cout << _UIElements.size() << std::endl;
	}
}