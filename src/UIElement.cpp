#include "UIElement.h"

UIElement::UIElement(GameObject* gameObject) : Component(gameObject)
{
	_gameObject = gameObject;
}

void UIElement::Update() {};