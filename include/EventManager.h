#pragma once
#include "Entity.h"
#include "Component.h"
#include "EventComponent.h"
#include <vector>

struct MousePosition{
	int x;
	int y;
};

enum MouseEvent {
	MouseEnter,
	MouseLeave,
	MouseDown,
	MouseUp
}MouseEvent;

class EventManager
{
private:
	std::vector<EventComponent*> mouseEnter;
	std::vector<EventComponent*> mouseLeave;
	std::vector<EventComponent*> mouseDown;
	std::vector<EventComponent*> mouseUp;
public:
	EventManager();
	void addMouseEnterEvent();
	void addMouseLeaveEvent();
	void addMouseDownEvent();
	void addMouseUpEvent();
	void update();
};