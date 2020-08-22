#pragma once

#include "Scene.h"
#include "SDL.h"
#include "MenuOption.h"
#include <vector>
#include "map.h"

class MainMenu : public Scene
{

private:
	std::vector<MenuOption*> menuOptions;
	Map* map;
public:

	MainMenu();

	void onCreate();
	void onDestroy();

	void onActivate();
	void onDeactivate();
};