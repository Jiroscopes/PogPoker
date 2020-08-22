#pragma once

#include "Scene.h"
#include "SDL.h"
#include "MenuOption.h"
#include <vector>

class MainMenu : public Scene
{

private:
	std::vector<MenuOption*> menuOptions;

public:

	MainMenu();

	void onCreate();
	void onDestroy();

	void onActivate();
	void onDeactivate();
};