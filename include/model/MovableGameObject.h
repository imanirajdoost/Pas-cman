#ifndef MOVABLEGAMEOBJECT_H
#define MOVABLEGAMEOBJECT_H

#include "model/component/AnimationComponent.h"
#include "GameObject.h"

class MovableGameObject : public GameObject, public MoveComponent, public AnimationComponent {

};

#endif