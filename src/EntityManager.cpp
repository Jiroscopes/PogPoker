#include "EntityManager.h"
#include "CardComponent.h"
#include <iostream>

void EntityManager::addEntity(Entity* entity)
{
	//std::cout << "Added" << std::endl;
	entities.push_back(entity);
}

Entity* EntityManager::getEntity(int id)
{
	return entities[id];
}

void EntityManager::render(SDL_Renderer* rendererRef)
{
	for (Entity* ent : entities)
	{	
		//std::cout << "Updating: " << ent->getComponent<CardComponent*>(1)->getFilename() << std::endl;
		ent->render(rendererRef);
	}
}

void EntityManager::update()
{
	for (Entity* ent : entities)
	{
		ent->update();
	}
}