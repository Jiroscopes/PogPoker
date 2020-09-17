#pragma once
#include "Entity.h"
#include "SDL.h"

class EntityManager
{
private:
	unsigned int entityID;
	std::vector<Entity*> entities;
public:
	EntityManager();

	Entity* getEntity(int id);
	
	void createEntity();

	void addEntity(Entity* entity);
	void removeEntity(Entity* id);

	unsigned int getLastInsertedID();

	void update();
	void render();
};