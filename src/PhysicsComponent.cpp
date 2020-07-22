#include "PhysicsComponent.h"

PhysicsComponent::PhysicsComponent(Entity* owner, Position pos, Size size)
{
	owner = owner;
	mPos = pos;
	mSize = size;
}

void PhysicsComponent::update()
{
	
}