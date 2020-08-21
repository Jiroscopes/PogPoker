#pragma once

#include "Scene.h"
#include "SDL.h"

class MainMenu : public Scene
{

private:
	SDL_Rect testButton;
public:

	MainMenu();

	void onCreate();
	void onDestroy();

	void onActivate();
	void onDeactivate();
};