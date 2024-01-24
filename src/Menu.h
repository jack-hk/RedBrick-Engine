#pragma once
#include "Scene.h"
#include "UIElement.h"

// A menu is where UI navigation happens.
class Menu : public Scene
{
public:
	Menu(const char* sceneName);
	void Update() override;

private:
	std::vector<UIElement*> _UIElements;
};

