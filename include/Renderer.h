#pragma once
#include <vector>
#include "SpriteComponent.h"
#include "PositionComponent.h"

class Renderer
{
private:
	std::vector<SpriteComponent*> sprites;
public:
	Renderer();
	~Renderer();
	void render();
	void addSprite(SpriteComponent* sprite);
	void removeSprite(SpriteComponent* sprite, int index) {};
};