#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "component/SpriteComponent.h"
#include "component/ColliderComponent.h"

class GameObject : public SpriteComponent, public ColliderComponent {

};

#endif