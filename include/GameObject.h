#pragma once
#include "game.h"

class GameObject
{
private:
	int xpos;
	int ypos;
	int height;
	int width;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;

public:
	GameObject(const char* textureSheet, int x, int y, int h, int w);
	~GameObject();

	void update(int x, int y, int display_height, int display_width);
	void render();


};