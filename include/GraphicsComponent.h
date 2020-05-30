#pragma once
#include "SDL.h"
#include "PositionComponent.h"
//#include "SDL_image.h"

class GraphicsComponent
{
private:
	
	SDL_Rect srcRect, destRect;
public:
	GraphicsComponent(const char* textureSheet, PositionComponent* position);
	~GraphicsComponent();
	void update();
};
