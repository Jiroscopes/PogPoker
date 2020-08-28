#include "EntityManager.h"
#include <iostream>

EntityManager::EntityManager() : entityID(0) {}

void EntityManager::addEntity(Entity* entity)
{
	entity->setID(getLastInsertedID());
	//std::cout << "Added" << std::endl;
	entities.push_back(entity);
	entityID++;
}


Entity* EntityManager::getEntity(int id)
{
	return entities[id];
}

void EntityManager::removeEntity(Entity* entAddr)
{
	for (std::vector<Entity*>::iterator it = entities.begin(); it != entities.end(); it++)
	{
		if (*it == entAddr)
		{
			// erase() invalidates the iterator becuase the elements have to shift
			it = entities.erase(it);
		}
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

