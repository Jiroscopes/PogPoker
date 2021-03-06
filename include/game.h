#pragma once
#include <iostream>
#include <vector>
#include "SDL.h"
#include "SDL_image.h"
#include "EventManager.h"
#include "Easing.h"
#include "EntityManager.h"
#include "SceneStateMachine.h"

#undef main

class Game
{
private:
	bool isRunning;
	SDL_Window* window;
	int count = 0;


public:

	int window_height;
	int window_width;
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();

	bool running();

	static SDL_Renderer* renderer;
	static EntityManager* entityManager;
	static EventManager* eventManager;
	static Easing* easingMan;
	static SceneStateMachine* sceneManager;
};