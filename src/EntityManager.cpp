#include "EntityManager.h"
#include <iostream>

void EntityManager::addEntity(Entity* entity)
{
	//std::cout << "Added" << std::endl;
	entities.push_back(entity);
	entityID++;
}


Entity* EntityManager::getEntity(int id)
{
	return entities[id];
}

void EntityManager::removeEntity(unsigned int id)
{
	if (id <= entities.size())
	{
		entities[id] = 0;
	}
}

unsigned int EntityManager::getLastInsertedID()
{
	return entityID;
}

void EntityManager::render()
{
	for (Entity* ent : entities)
	{	
		
		ent->render();
	}
}

void EntityManager::update()
{
	for (Entity* ent : entities)
	{
		ent->update();
	}
}

