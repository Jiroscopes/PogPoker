#include "Entity.h"
#include <iostream>
#include <algorithm>
#include "GraphicsComponent.h"

Entity::Entity()
{}

void Entity::update()
{
	for (std::pair<int, Component*> comp : componentArray)
	{
		comp.second->update();
	}
}

void Entity::render()
{
	GraphicsComponent* gfx = this->getComponent<GraphicsComponent*>(2);

	gfx->render();
}
