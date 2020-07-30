#pragma once
#include "Component.h"
#include "Entity.h"

struct Position {
	int x;
	int y;
};

struct Size {
	int width;
	int height;
};

struct Boundary {
	int leftX;
	int rightX;
	int topY;
	int bottomY;

};

class PhysicsComponent : public Component
{
private:
	Entity* owner;
	Position mPos;
	Position mNewPosition;
	Boundary mBoundary;
	Size mNewSize;
	Size mSize;


public:
	int id = 3;
	PhysicsComponent(Entity* owner, Position pos, Size size);
	void updatePosition();
	void update();
	Position* getPosition() { return &mPos; }
	Size* getSize() { return &mSize; }
	void setNewPosition(Position pos);
	void setBoundary(Boundary boundary);
	bool checkBoundary();
	void setNewSize(Size size);
};