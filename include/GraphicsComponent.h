#pragma once
#include "Component.h"
#include "Entity.h"
#include "SDL.h"
//#include "SDL_image.h"

class GraphicsComponent : public Component
{
private:
	Entity* owner;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect; // src = texture, dest = size on screen
public:
	GraphicsComponent(const char* textureSheet, Entity* entity, int h, int w);
	~GraphicsComponent();
	void setHeight(int h) { srcRect.h = h; }
	void setWidth(int w) { srcRect.w = w; }
	void update();
	void render(SDL_Renderer* renderer);
};
