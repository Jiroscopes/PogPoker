#include "GraphicsComponent.h"
#include "TextureManager.h"
#include "EntityManager.h"
#include "game.h"

GraphicsComponent::GraphicsComponent(const char* textureSheet, Entity* entity, int h, int w)
{
	owner = entity;
	objTexture = TextureManager::LoadTexture(textureSheet);
	//std::cout << "Loading Texture: " << textureSheet << std::endl;
	srcRect.x = entity->getXPosition();
	srcRect.y = entity->getYPosition();
	srcRect.h = h;
	srcRect.w = w;
	destRect.h = 726;
	destRect.w = 500;
}

GraphicsComponent::~GraphicsComponent()
{}

void GraphicsComponent::update()
{
	destRect.x = 200;
	destRect.y = 200;
	srcRect.x = 0;
	srcRect.y = 0;
}

void GraphicsComponent::render()
{	
	//std::cout << renderer << std::endl;

	//SDL_Rect test1;
	//SDL_Rect test2;

	//test1.x = 0;
	//test1.y = 0;
	//test1.h = 500;
	//test1.w = 500;

	//test2.x = 0;
	//test2.y = 0;
	//test2.h = 500;
	//test2.w = 500;

	//std::cout << objTexture << std::endl;

	//SDL_Texture* testTex = TextureManager::LoadTexture("../assets/cards/1.png");
	if (SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect))
	{
		std::cout << "Render Success" << std::endl;
	};
}
