#pragma once
#include "Component.h"
#include "Entity.h"
#include "SDL.h"
#include "PhysicsComponent.h"
#include "Timer.h"

// ID 2


class GraphicsComponent : public Component
{
private:
	Entity* owner;
	SDL_Texture* objTexture;
	SDL_Rect mBox, tBox; // src = texture, dest = size on screen
	PhysicsComponent* mEntityPhysics;
	bool renderFlag;
	Timer* clock;
	Position tempTexturePosition = { 0, 0 };
public:
	int id = 2;
	GraphicsComponent(Entity* entity, const char* textureSheet, Size textureSize);
	~GraphicsComponent();
	void setHeight(int h) { mBox.h = h; }
	void setWidth(int w) { mBox.w = w; }
	void setRenderFlag(bool flagValue);
	bool getRenderFlag();
	void setTextureBoxPosition(Position newPos);
	void updateTextureBox();
	void update();
	void render();
};
