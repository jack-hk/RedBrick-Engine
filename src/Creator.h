#pragma once

#include "Scene.h"

class Creator 
{
public:
    virtual ~Creator() {};
    virtual Scene* FactoryMethod(const char* sceneName) const = 0;
};

