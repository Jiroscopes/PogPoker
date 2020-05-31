#include "EntityManager.h"

void EntityManager::addEntity(Entity* entity)
{
	entities.push_back(entity);
}

Entity* EntityManager::getEntity(int id)
{
	return entities[id];
}

void EntityManager::render()
{}

void EntityManager::update()
{}