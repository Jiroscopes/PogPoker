#pragma once
#include "Entity.h"
#include "SDL.h"

class EntityManager
{
private:
	std::vector<Entity*> entities;
public:
	void addEntity(Entity* entity);
	Entity* getEntity(int id);
	//void addRenderer(SDL_Renderer* rendererRef) { renderer = rendererRef; }
	//SDL_Renderer* getRenderer() { return renderer; }
	void update();
	void render();
};