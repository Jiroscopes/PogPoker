#include "EntityManager.h"
#include <iostream>

EntityManager::EntityManager() : entityID(0) {}

void EntityManager::addEntity(Entity* entity)
{
    //entity->setID(getLastInsertedID());
    //std::cout << "Added" << std::endl;
    std::unique_ptr<Entity> uniqPtr{ entity };
    entities.emplace_back(std::move(uniqPtr));
}

void EntityManager::removeEntity(Entity* entAddr)
{}

void EntityManager::render()
{
    for (auto& ent : entities)
    {
        ent->render();
    }
}

void EntityManager::update()
{
    for (auto& ent : entities)
    {
        ent->update();
    }
}



