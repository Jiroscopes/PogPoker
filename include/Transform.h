#pragma once
#include "Component.h"
#include "Vect2D.h"

class Transform : public Component
{
private:
public:

    Vect2I position = Vect2I();
    Vect2I scale = Vect2I(1, 1);
    int rotation = 0.0f;

    Entity* entity;
    Transform() = default;

    Transform(int x, int y)
    {
        position.x = x;
        position.y = y;
        scale.ones();
        rotation = 0.0f;
    }

    Transform(int x, int y, int scx, int scy)
    {
        position.x = x;
        position.y = y;

        scale.x = scx;
        scale.y = scy;
    }

    Transform(int x, int y, int scx, int scy, int r)
    {
        position.x = x;
        position.y = y;

        scale.x = scx;
        scale.y = scy;

        rotation = r;
    }

    ~Transform() = default;

    bool inti() { return true; }

    void render() {}

    void update() {}

};