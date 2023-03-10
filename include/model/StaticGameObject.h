#ifndef STATICGAMEOBJECT_H
#define STATICGAMEOBJECT_H

#include "model/component/TransformComponent.h"
#include "GameObject.h"

class StaticGameObject : public GameObject, public TransformComponent {

};

#endif