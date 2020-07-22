#pragma once
#include "Entity.h"
#include "Component.h"
#include "EventComponent.h"
#include <vector>

struct MousePosition{
	int x;
	int y;
};

class EventManager
{
private:
	std::vector<EventComponent*> mouseMotion;
	std::vector<EventComponent*> mouseDown;
	std::vector<EventComponent*> mouseUp;
public:
	EventManager();
	void registerEvent(EventComponent* eventHandler, MouseEvent eventType);
	void update(SDL_Event* event);
};