#include "PhysicsComponent.h"

PhysicsComponent::PhysicsComponent(Entity* owner, Position pos, Size size)
{
	owner = owner;
	mPos = pos;
	mSize = size;
	mNewPosition = pos;
	//mNewPosition = size;
}

void PhysicsComponent::updatePosition()
{
	if (mPos.x != mNewPosition.x) {
		if (mNewPosition.x > mPos.x)
		{
			mPos.x++;
		}
		else
		{
			mPos.x--;
		}
	}
	else if (mPos.y != mNewPosition.y)
	{
		if (mNewPosition.y > mPos.y)
		{
			mPos.y++;
		}
		else {
			mPos.y = mPos.y - 1 * 2;
		}
	}
}

void PhysicsComponent::setNewPosition(Position pos)
{
	mNewPosition = pos;
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