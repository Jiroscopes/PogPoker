#pragma once
#include "Entity.h"
#include "EventComponent.h"

class MenuOption : public Entity
{
private:
	bool active = false;
	std::vector<MouseEvent> events{ MouseDown };
	unsigned int id;
public:
	MenuOption(unsigned int id);
	void update();
	void triggerEvent(int eventType);
};