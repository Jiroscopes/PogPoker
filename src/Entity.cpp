#include "Entity.h"
#include <iostream>
#include <algorithm>
#include "GraphicsComponent.h"

Entity::Entity()
{
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
