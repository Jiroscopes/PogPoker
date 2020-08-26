#pragma once
#include "Entity.h"
#include "EventComponent.h"
#include "PhysicsComponent.h"

class MenuOption : public Entity
{
private:
	bool active = false;
	bool mouseInside = false;

	std::vector<MouseEvent> events{ MouseDown, MouseMotion };
	Position position = { 0, 0 };
	const char* texturePath;
	unsigned int id;
public:
	MenuOption(unsigned int id, const char* texturePath, Position pos);
	void update();
	void triggerEvent(int eventType);
};