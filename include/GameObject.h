#pragma once
#include "game.h"

class GameObject
{
private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;

public:
	GameObject(const char* textureSheet, int x, int y);
	~GameObject();

	void update();
	void render();


};