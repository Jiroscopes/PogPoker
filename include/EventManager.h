#pragma once
#include "Entity.h"
#include "Component.h"
#include <vector>
#include <memory>

enum MouseEvent {
    MouseMotion,
    MouseDown,
    MouseUp
};

struct MousePosition{
    int x;
    int y;
};

class EventManager
{
private:
    std::vector<std::unique_ptr<Component>> mouseMotion;
    std::vector<std::unique_ptr<Component>> mouseDown;
    std::vector<std::unique_ptr<Component>> mouseUp;

public:
    EventManager();
    void registerEvent(Component* componentThatCares, MouseEvent eventType);
    //void removeEvent(EventComponent& eventComp);
    void update(SDL_Event* event);
};