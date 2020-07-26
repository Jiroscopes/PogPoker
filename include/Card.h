#pragma once
#include "Entity.h"
#include <string>

class Card : public Entity
{
private:
	int cardNum;
	int suit;
	int rank;
	std::string filename = "../assets/cards/";
public:
	int id = 1;
	Card(int cardNum);
	int getRank();
	int getSuit();
	int getCardNum();
	std::string getFilename();
	void update();
	void triggerEvent(int eventType);
};