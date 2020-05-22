#include "GameObject.h"

class Card 
{
    private:
        static const char* SUITS[];
        static const int RANKS[];
        int card;
		int suit;
		int rank;
    public:
        Card();
        Card(int cardNum);
        int getRank();
        int getSuit();
		GameObject* cardObj;
};
