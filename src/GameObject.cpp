#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, int x, int y, int img_height, int img_width)
{
	objTexture = TextureManager::LoadTexture(textureSheet);

	xpos = x;
	ypos = y;
	height = img_height;
	width = img_width;
}

GameObject::~GameObject()
{

}

void GameObject::update(int x, int y, int display_height, int display_width)
{

	xpos = x;
	ypos = y;

	srcRect.h = height; // 726
	srcRect.w = width; // 500
	srcRect.x = 0;
	srcRect.y = 0;


	destRect.h = display_height; // 274
	destRect.w = display_width; // 188
	destRect.x = xpos;
	destRect.y = ypos;
}

void GameObject::render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}