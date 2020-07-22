#include "Entity.h"
#include <iostream>
#include <algorithm>
#include "GraphicsComponent.h"

Entity::Entity(int x, int y)
{
	xPos = x;
	yPos = y;
}

void Entity::update()
{
	for (Component* comp : components)
	{
		comp->update();
	}
}

void Entity::render()
{
	GraphicsComponent* gfx = this->getComponent<GraphicsComponent*>(2);

	gfx->render();
}
