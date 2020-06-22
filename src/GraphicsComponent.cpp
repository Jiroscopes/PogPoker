#include "GraphicsComponent.h"
#include "TextureManager.h"
#include "EntityManager.h"

GraphicsComponent::GraphicsComponent(const char* textureSheet, Entity* entity, int h, int w)
{
	owner = entity;
	objTexture = TextureManager::LoadTexture(textureSheet);
	//std::cout << "Loading Texture: " << textureSheet << std::endl;
	srcRect.x = entity->getXPosition();
	srcRect.y = entity->getYPosition();
	srcRect.h = h;
	srcRect.w = w;
	destRect.h = 200;
	destRect.w = 200;
}

GraphicsComponent::~GraphicsComponent()
{}

void GraphicsComponent::update()
{
	destRect.x = 200;
	destRect.y = 200;
	srcRect.x = 200;
	srcRect.y = 200;
}

void GraphicsComponent::render(SDL_Renderer* renderer)
{	
	std::cout << renderer << std::endl;
	if (SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect))
	{
		std::cout << "Render Success" << std::endl;
	};
}
