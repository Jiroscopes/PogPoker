#pragma once
#include "Component.h"
#include <vector>

enum MouseEvent {
	MouseMotion,
	MouseDown,
	MouseUp
};

class EventComponent : public Component
{
private:
	MouseEvent eventType;
public:
	int id = 4;
	EventComponent(std::vector<MouseEvent> mouseEvents);
	void triggerEvent(MouseEvent eventType);
	void update() {}
};