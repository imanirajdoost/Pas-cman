#ifndef STATICGAMEOBJECT_H
#define STATICGAMEOBJECT_H

#include "GameObject.h"
#include "component/TransformComponent.h"

class StaticGameObject : public GameObject, public TransformComponent {

};

#endif