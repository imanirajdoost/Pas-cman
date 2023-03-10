#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "model/component/ColliderComponent.h"
#include "model/component/SpriteComponent.h"

using namespace std;

class GameObject : public SpriteComponent, public ColliderComponent {

};

#endif