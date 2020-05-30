#include "GraphicsComponent.h"
#include "TextureManager.h"

GraphicsComponent::GraphicsComponent(const char* textureSheet, PositionComponent* position)
{
	objTexture = TextureManager::LoadTexture(textureSheet);

	srcRect.x = position->getX();
	srcRect.y = position->getY();

}

GraphicsComponent::~GraphicsComponent()
{}

void GraphicsComponent::update()
{

}
