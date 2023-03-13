#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "component/SpriteComponent.h"
#include "component/ColliderComponent.h"
#include "component/AnimationComponent.h"

class GameObject : public AnimationComponent, public ColliderComponent {
};

#endif