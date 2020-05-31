#include "Entity.h"

template <class T> T Entity::addComponent(T* component)
{
	components.push_back(component);
}

void Entity::update()
{}

void Entity::render()
{}
