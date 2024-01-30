#pragma once

#include "Creator.h"
#include "Menu.h"

class MenuCreator : public Creator
{
public:
	Scene* FactoryMethod(const char* sceneName) const override
	{
		return new Menu(sceneName);
	}
};