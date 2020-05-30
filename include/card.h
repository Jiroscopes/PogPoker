#include "GameObject.h"
#include "PositionComponent.h"
#include "SpriteComponent.h"

class Card 
{
    private:
        //static const char* SUITS[];
        //static const int RANKS[];
        int card;
		int suit;
		int rank;
		PositionComponent positionComponent;
		SpriteComponent spriteComponent;
    public:
        Card();
        Card(int cardNum);
        int getRank();
        int getSuit();
		void update();
		GameObject* cardObj;
		
};
