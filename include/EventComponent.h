#pragma once
#include "Component.h"
#include "Entity.h"
#include <vector>

// ID 4

enum MouseEvent {
	MouseMotion,
	MouseDown,
	MouseUp
};

class EventComponent : public Component
{
private:
	MouseEvent eventType;
	Entity* owner;
public:
	int id = 4;
	EventComponent(Entity* owner, std::vector<MouseEvent> mouseEvents);
	void triggerEvent(MouseEvent eventType);
	void update() {}
};