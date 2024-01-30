#pragma once

#include "Creator.h"
#include "Level.h"

class LevelCreator : public Creator
{
public:
	Scene* FactoryMethod(const char* sceneName) const override
	{
		return new Level(sceneName);
	}
};