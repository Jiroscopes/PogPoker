#include "GraphicsComponent.h"
#include "TextureManager.h"
#include "EntityManager.h"
#include "game.h"

GraphicsComponent::GraphicsComponent(Entity* entity, const char* textureSheet, Size textureSize) : textureSize(textureSize)
{
	owner = entity;
	renderFlag = true;

	mEntityPhysics = entity->getComponent<PhysicsComponent*>(3);
	
	objTexture = TextureManager::LoadTexture(textureSheet);
	
	Position* entityPos = mEntityPhysics->getPosition();
	Size* entitySize = mEntityPhysics->getSize();

	// mBox is size on screen
	// tBox is texture

	mBox.x = entityPos->x;
	mBox.y = entityPos->y;

	mBox.h = entitySize->height;
	mBox.w = entitySize->width;

	tBox.h = textureSize.height;
	tBox.w = textureSize.width;
	currentTextureBoxPosition = { 0,0 };
	clock = new Timer();
}

GraphicsComponent::~GraphicsComponent()
{}

void GraphicsComponent::setTextureBoxPosition(Position newPos)
{
	tempTexturePosition.x = newPos.x;
	tempTexturePosition.y = newPos.y;
	clock->start();
}

void GraphicsComponent::updateTextureBox()
{
	//tBox.x = Game::easingMan->easeOut(clock->getTicks(), tBox.x, (tempTexturePosition.x - tBox.x) + 1, 3000);
	//tBox.y = Game::easingMan->easeOut(clock->getTicks(), tBox.y, (tempTexturePosition.y - tBox.y) + 1, 3000);
	tBox.x = tempTexturePosition.x;
	tBox.y = tempTexturePosition.y;
	currentTextureBoxPosition = { tBox.x, tBox.y };
}

void GraphicsComponent::setRenderFlag(bool flagValue)
{
	renderFlag = flagValue;
}

bool GraphicsComponent::getRenderFlag()
{
	return renderFlag;
}

void GraphicsComponent::update()
{
	Position* entityPos = mEntityPhysics->getPosition();
	Size* entitySize = mEntityPhysics->getSize();
	mBox.x = entityPos->x;
	mBox.y = entityPos->y;
	mBox.h = entitySize->height;
	mBox.w = entitySize->width;
	this->updateTextureBox();
}

void GraphicsComponent::render()
{	
	// If the element is meant to be rendered


	if (renderFlag)
	{
		SDL_RenderCopy(Game::renderer, objTexture, &tBox, &mBox);
	}
}
