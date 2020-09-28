#pragma once
#include "Entity.h"
#include "SDL.h"
#include <memory>

class EntityManager
{
private:
    unsigned int entityID;
    std::vector<std::unique_ptr<Entity>> entities;
public:
    EntityManager();

    void addEntity(Entity* entity);
    void removeEntity(Entity* id);

    void update();
    void render();
};