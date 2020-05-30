#pragma once

class PositionComponent
{
private:
	int xpos;
	int ypos;
public:
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
};