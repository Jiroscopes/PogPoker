#pragma once
#include "Scene.h"
#include "deck.h"
#include "map.h"

class PlayScene : public Scene
{
private:

	Deck* deck;
	Map* map;

public:
	PlayScene();

	void onCreate() = 0;
	void onDestroy() = 0;

	void onActivate();
	void onDeactivate();

	//void setSceneSwitch();
};