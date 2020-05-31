#pragma once
#include "Entity.h"

class Component
{
private:
public:
	Entity* owner;
	virtual void update();
	//virtual void render();
};