#pragma once
#include "Component.h"
#include <string>

class CardComponent : public Component
{
    private:
        int card;
		int suit;
		int rank;
		std::string filename;
    public:
		int id = 1;
        CardComponent(int cardNum);
        int getRank();
        int getSuit();
		int getCardNum();
		std::string getFilename();
		void update();
};
