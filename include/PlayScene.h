#pragma once
#include "Scene.h"
#include "deck.h"
#include "map.h"
#include "GraphicsComponent.h"

class PlayScene : public Scene
{
private:

	Deck* deck;
	Map* map;
	std::vector<Entity*> sceneEntities;
	std::vector<GraphicsComponent*> sceneEntitiesGraphics;

	void loadEntityIntoVectors(Entity* ent);

public:
	PlayScene();

	void onCreate();
	void onDestroy();

	void onActivate();
	void onDeactivate();

	void renderMap();
	//void setSceneSwitch();
};