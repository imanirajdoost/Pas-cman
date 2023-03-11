#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "component/SpriteComponent.h"
#include "component/ColliderComponent.h"
#include "../controller/SDLViewController.h"

class GameObject : public SpriteComponent, public ColliderComponent {
public:
    virtual void draw(const SDLViewController& viewController);
};

#endif