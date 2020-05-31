#pragma once
#include "Entity.h"


class EntityManager
{
private:
	std::vector<Entity*> entities;
public:
	void addEntity(Entity* entity);
	Entity* getEntity(int id);
	void update();
	void render();
};