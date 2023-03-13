#ifndef MOVABLEGAMEOBJECT_H
#define MOVABLEGAMEOBJECT_H

#include "GameObject.h"
#include "component/MoveComponent.h"
#include "component/AnimationComponent.h"

class MovableGameObject : public GameObject, public MoveComponent {
};

#endif