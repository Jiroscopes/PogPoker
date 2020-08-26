#include "PhysicsComponent.h"
#include "game.h"
#include <iostream>
#include <cmath>

// Position equality comparisons
bool operator == (const Position& lhs, const Position& rhs)
{
	return lhs.x == rhs.x && lhs.y == rhs.y;
}
bool operator != (const Position& lhs, const Position& rhs)
{
	return lhs.x != rhs.x || lhs.y != rhs.y;
}

PhysicsComponent::PhysicsComponent(Entity* owner, Position pos, Size size)
{
	owner = owner;
	mPos = pos;
	mSize = size;
	homePosition = pos;
	mNewPosition = pos;
	lastStablePosition = pos;
	clock = new Timer();
}

PhysicsComponent::~PhysicsComponent()
{
	delete clock;
}

void PhysicsComponent::updatePosition()
{

	if (mPos != mNewPosition)
	{
		mPos.x = Game::easingMan->easeOut(clock->getTicks(), mPos.x, (mNewPosition.x - mPos.x) + 1, 3000);
		mPos.y = Game::easingMan->easeOut(clock->getTicks(), mPos.y, (mNewPosition.y - mPos.y) + 1, 3000);
	}
	else
	{
		lastStablePosition = mPos;
	}
}

Position PhysicsComponent::getHomePosition()
{
	return homePosition;
}

void PhysicsComponent::setNewPosition(Position pos)
{
	mNewPosition = pos;
	clock->start();
}

void PhysicsComponent::setNewSize(Size size)
{
	mNewSize = size;
}


void PhysicsComponent::update()
{
	this->updatePosition();
	//updateSize();
}

void PhysicsComponent::setSpeed(float speed)
{
	animationSpeed = speed;
}
