#pragma once
#include "SDL.h"

class SpriteComponent
{
private:
	SDL_Texture* objTexture;
	int height;
	int width;
public:
	void setHeight(int h) { height = h; }
	void setWidth(int w) { width = w; }
	int getHeight() { return height; }
	int getWidth() { return width; }
};