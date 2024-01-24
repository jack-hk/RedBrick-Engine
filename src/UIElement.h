#pragma once

#include "Component.h"
#include "GameObject.h"
#include "Math.h"

class UIElement : public Component
{
public:
	UIElement(GameObject* gameObject);

	void Update() override;
};