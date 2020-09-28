#pragma once
#include "tile.h"
#include <vector>

class Layer
{
private:
	std::vector<Tile*> tiles;
public:
	Layer(int numOfTiles);
	std::vector<Tile*>* getVector();
};