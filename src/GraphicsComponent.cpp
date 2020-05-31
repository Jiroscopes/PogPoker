#include "GraphicsComponent.h"
#include "TextureManager.h"

GraphicsComponent::GraphicsComponent(const char* textureSheet, Entity* entity, int h, int w)
{
	owner = entity;
	objTexture = TextureManager::LoadTexture(textureSheet);

	srcRect.x = entity->getXPosition();
	srcRect.y = entity->getYPosition();
	srcRect.h = h;
	srcRect.w = w;
}

GraphicsComponent::~GraphicsComponent()
{}

void GraphicsComponent::update()
{
	srcRect.x = owner->getXPosition();
	srcRect.y = owner->getYPosition();
}
