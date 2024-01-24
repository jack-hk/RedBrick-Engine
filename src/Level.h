#pragma once
#include "Scene.h"

// A level is where gameplay happens.
class Level : public Scene
{
public:
	Level(const char* sceneName);
	void Update() override;
};