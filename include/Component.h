#pragma once

class Component
{
private:
public:
	int id;
	virtual void update() = 0;
	//virtual void render();
};