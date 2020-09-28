#include "EventComponent.h"
#include "EventManager.h"
#include "game.h"
#include <iostream>

EventComponent::EventComponent(Entity* owner, std::vector<MouseEvent> mouseEvents)
{
	this->owner = owner;

	for (MouseEvent eventType : mouseEvents)
	{
		switch (eventType)
		{
		case MouseMotion:
			Game::eventManager->registerEvent(this, MouseMotion);
			break;
		case MouseDown:
			Game::eventManager->registerEvent(this, MouseDown);
			break;
		case MouseUp:
			Game::eventManager->registerEvent(this, MouseUp);
			break;
		}
	}
}

void EventComponent::triggerEvent(MouseEvent eventType)
{
	//std::cout << &owner << std::endl;
	owner->triggerEvent(eventType);
}