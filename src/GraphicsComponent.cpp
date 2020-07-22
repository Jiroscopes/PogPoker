#include "GraphicsComponent.h"
#include "TextureManager.h"
#include "EntityManager.h"
#include "game.h"

GraphicsComponent::GraphicsComponent(const char* textureSheet, Entity* entity)
{
	owner = entity;
	mEntityPhysics = entity->getComponent<PhysicsComponent*>(3);

	objTexture = TextureManager::LoadTexture(textureSheet);
	Position* entityPos = mEntityPhysics->getPosition();
	Size* entitySize = mEntityPhysics->getSize();

	mBox.x = entityPos->x;
	mBox.y = entityPos->y;

	mBox.h = entitySize->height;
	mBox.w = entitySize->width;

	tBox.h = 726;
	tBox.w = 500;
}

GraphicsComponent::~GraphicsComponent()
{}

void GraphicsComponent::update()
{
	Position* entityPos = mEntityPhysics->getPosition();
	Size* entitySize = mEntityPhysics->getSize();
	mBox.x = entityPos->x;
	mBox.y = entityPos->y;
	mBox.h = entitySize->height;
	mBox.w = entitySize->width;
	tBox.x = 0;
	tBox.y = 0;
}

void GraphicsComponent::render()
{	
	if (SDL_RenderCopy(Game::renderer, objTexture, &tBox, &mBox))
	{
		std::cout << "Render Success" << std::endl;
	};
}
