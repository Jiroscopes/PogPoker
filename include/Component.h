#pragma once

class Entity;

class Component
{
private:
public:
    // Hold pointer to its owner
    Entity* entity;

    virtual bool init() { return true; }
    virtual void update() = 0;

    // Not required by all components
    virtual void triggerEvent(int eventType) {}
    virtual void render() {}
};