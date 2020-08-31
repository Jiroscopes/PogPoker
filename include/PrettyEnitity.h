#pragma once
#include "Entity.h"

// This Enitity type is for things that do nothing. No events. Basically a shell


class PrettyEntity : public Entity
{
private:
public:
	PrettyEntity();
	void update();
	void triggerEvent(int event);
};