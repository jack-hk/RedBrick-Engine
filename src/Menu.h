#pragma once
#include "Scene.h"

// A menu is where UI navigation happens.
class Menu : public Scene
{
public:
	Menu(const char* sceneName);
	void Update() override;
};