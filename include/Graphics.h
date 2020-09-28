#pragma once
#include "Component.h"
#include "Entity.h"
#include "SDL.h"
#include "Vect2D.h"
#include "Transform.h"
//#include "PhysicsComponent.h"
#include "Timer.h"

class Graphics : public Component
{
private:
    SDL_Texture* objTexture;
    SDL_Rect mBox, tBox; // src = texture, dest = size on screen

    Transform entityTransformComponent;

    bool renderFlag;

    Timer* clock;

    const char* filename;

    Vect2I textureScale;
    Vect2I tempTexturePosition = { 0, 0 };
    Vect2I currentTextureBoxPosition;
public:

    Entity* entity;

    Graphics() = default;
    Graphics(const char* textureSheet, Vect2I textureScale);

    ~Graphics() = default;

    void setHeight(int h) { mBox.h = h; }
    void setWidth(int w) { mBox.w = w; }

    void setRenderFlag(bool flagValue);
    bool getRenderFlag();

    // represents the frame size
    Vect2I getTextureScale() { return textureScale; }

    Vect2I getTextureBoxPosition() { return currentTextureBoxPosition; }

    void setTextureBoxPosition(Vect2I newPos);

    void updateTextureBox();

    bool init() override;

    void update();
    void render();
};
