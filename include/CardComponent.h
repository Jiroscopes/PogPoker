#pragma once
#include "Component.h"

class CardComponent : public Component
{
    private:
        int card;
		int suit;
		int rank;
    public:
        CardComponent(int cardNum);
        int getRank();
        int getSuit();
		void update();
};
