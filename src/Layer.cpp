#include "Layer.h"
#include <iostream>

Layer::Layer(int numOfTiles) : tiles(numOfTiles)
{

}

std::vector<Tile*>* Layer::getVector()
{
	return &tiles;
}