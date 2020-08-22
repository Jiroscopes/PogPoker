#pragma once
#include "Entity.h"
#include "SDL.h"

class EntityManager
{
private:
	unsigned int entityID;
	std::vector<Entity*> entities;
public:
	Entity* getEntity(int id);
	
	void addEntity(Entity* entity);
	void removeEntity(unsigned int id);

	unsigned int getLastInsertedID();

	//void addRenderer(SDL_Renderer* rendererRef) { renderer = rendererRef; }
	//SDL_Renderer* getRenderer() { return renderer; }

	void update();
	void render();
};