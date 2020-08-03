#include "PhysicsComponent.h"
#include "game.h"
#include <iostream>
#include <cmath>

// Position equality comparisons
bool operator == (const Position& lhs, const Position& rhs)
{
	return lhs.x == rhs.x && lhs.y == rhs.y;
}

PhysicsComponent::PhysicsComponent(Entity* owner, Position pos, Size size)
{
	owner = owner;
	mPos = pos;
	mSize = size;
	mNewPosition = pos;
	homePosition = pos;
	//mNewPosition = size;
	clock = new Timer();
}

PhysicsComponent::~PhysicsComponent()
{
	delete clock;
}

void PhysicsComponent::updatePosition()
{
	if (mPos.x != mNewPosition.x) {
		if (mNewPosition.x > mPos.x)
		{
			//mPos.x = mPos.x + 1 * (animationSpeed * testTime);
		}
		else
		{
			mPos.x = mPos.x - 1 * animationSpeed;
		}
	}
	else if (mPos.y != mNewPosition.y)
	{

		if (mNewPosition.y > mPos.y)
		{
			mPos.y = mPos.y + 1; //* testTime
		}
		else {
			//std::cout << clock->getTicks() << std::endl;
			//std::cout << "Moved pixels: " << Game::easingMan->easeOut(clock->getTicks(), 0, 160, 1000) << std::endl;
			//std::cout << Game::easingMan->easeOut(clock->getTicks(), 560, 560 - 160, 1000) << std::endl;
			mPos.y = Game::easingMan->easeOut(clock->getTicks(), 560, 400, 3000);
		}
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
	//std::cout << clock->getTicks() << std::endl;
	this->updatePosition();
	//updateSize();
}

void PhysicsComponent::setSpeed(float speed)
{
	animationSpeed = speed;
}
