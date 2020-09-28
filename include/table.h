#pragma once
#include "TextureManager.h"

class Table : public Entity
{
private:
	//std::string filename = "../assets/table.png";
public:
	Table();

	void triggerEvent(int eventType);
	void update();
};