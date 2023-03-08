#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "model/component/SpriteComponent.h"
#include "model/component/ColliderComponent.h"
#include "model/component/TransformComponent.h"

using namespace std;

class GameObject : public SpriteComponent, public ColliderComponent {

};

#endif