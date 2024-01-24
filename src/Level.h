#pragma once
#include "Scene.h"

// A level is where gameplay happens.
class Level : public Scene
{
public:
	void Update() override;
};