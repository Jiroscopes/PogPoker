#pragma once

#include "Scene.h"
#include "SDL.h"
#include "MenuOption.h"
#include <vector>
#include "map.h"
#include "GraphicsComponent.h"

class MainMenu : public Scene
{

private:
	std::vector<Entity*> sceneEntities;
	std::vector<GraphicsComponent*> sceneEntitiesGraphics;
	Map* map;
public:

	MainMenu();

	void onCreate();
	void onDestroy();

	void onActivate();
	void onDeactivate();

	void loadEntityIntoVectors(Entity* ent);

	void renderMap();
};