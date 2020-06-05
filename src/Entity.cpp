#include "Entity.h"

void Entity::addComponent(Component* component)
{
	components.push_back(component);
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
	 
}
