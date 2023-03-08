#ifndef MOVABLEGAMEOBJECT_H
#define MOVABLEGAMEOBJECT_H

#include "GameObject.h"
#include "model/component/AnimationComponent.h"
#include "model/component/MoveComponent.h"

class MovableGameObject : public GameObject, public MoveComponent, public AnimationComponent {

};

#endif