#pragma once
#include "Entity.h"
#include <string>

class Card : public Entity
{
private:
	int cardNum;
	int suit;
	int rank;
	bool mouseInside = false;
	int animationSpeed = 10;
	std::string filename = "../assets/cards/";
public:
	int id = 1;
	Card(int cardNum);
	int getRank();
	int getSuit();
	int getCardNum();
	std::string getFilename();
	int getAnimationSpeed() {
		return animationSpeed;
	}
	void update();
	void triggerEvent(int eventType);
};