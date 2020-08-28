#include "EventManager.h"
#include <iostream>
EventManager::EventManager()
{

}

void EventManager::registerEvent(EventComponent* eventHandler, MouseEvent eventType)
{
	switch (eventType)
	{
	case MouseMotion:
		mouseMotion.push_back(eventHandler);
		//std::cout << "Mouse Motion Event Registered!" << std::endl;
		break;
	case MouseDown:
		mouseDown.push_back(eventHandler);
		//std::cout << "Mouse Down Event Registered!" << std::endl;
		break;
	case MouseUp:
		mouseUp.push_back(eventHandler);
		//std::cout << "Mouse Up Event Registered!" << std::endl;
		break;
	}
}

void EventManager::removeEvent(EventComponent* eventComp)
{

	// TODO redo this...its gross

	for (std::vector<EventComponent*>::iterator it = mouseMotion.begin(); it != mouseMotion.end(); it++)
	{
		if (*it == eventComp)
		{
			// erase() invalidates the iterator becuase the elements have to shift
			it = mouseMotion.erase(it);
		}
	}

	for (std::vector<EventComponent*>::iterator it = mouseDown.begin(); it != mouseDown.end(); it++)
	{
		if (*it == eventComp)
		{
			// erase() invalidates the iterator becuase the elements have to shift
			it = mouseDown.erase(it);
		}
	}

	for (std::vector<EventComponent*>::iterator it = mouseUp.begin(); it != mouseUp.end(); it++)
	{
		if (*it == eventComp)
		{
			// erase() invalidates the iterator becuase the elements have to shift
			it = mouseUp.erase(it);
		}
	}


}

void EventManager::update(SDL_Event* event)
{
	switch (event->type)
	{
	case SDL_MOUSEBUTTONUP:
		if (!mouseUp.empty())
		{
			for (EventComponent* x : mouseUp)
			{
				x->triggerEvent(MouseUp);
			}
		}
		break;
	case SDL_MOUSEBUTTONDOWN:
		if (!mouseDown.empty())
		{
			for (EventComponent* x : mouseDown)
			{
				x->triggerEvent(MouseDown);
			}
		}
		break;	
	case SDL_MOUSEMOTION:
		if (!mouseMotion.empty())
		{
			for (EventComponent* x : mouseMotion)
			{
				x->triggerEvent(MouseMotion);
			}
		}
		break;
	}
	
}