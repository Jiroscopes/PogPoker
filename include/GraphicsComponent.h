#pragma once
#include "Component.h"
#include "Entity.h"
#include "SDL.h"
#include "PhysicsComponent.h"


class GraphicsComponent : public Component
{
private:
	Entity* owner;
	SDL_Texture* objTexture;
	SDL_Rect mBox, tBox; // src = texture, dest = size on screen
	PhysicsComponent* mEntityPhysics;
	bool renderFlag;
public:
	int id = 2;
	GraphicsComponent(const char* textureSheet, Entity* entity);
	~GraphicsComponent();
	void setHeight(int h) { mBox.h = h; }
	void setWidth(int w) { mBox.w = w; }
	void setRenderFlag(bool flagValue);
	bool getRenderFlag();
	void update();
	void render();
};
