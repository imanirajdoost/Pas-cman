#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "header/model/component/TransformComponent.h"
#include "header/model/component/AnimationComponent.h"

class GameObject : public TransformComponent, public AnimationComponent {
public:
    GameObject();
    explicit GameObject(SDL_Rect defaultSp);
    GameObject(const string &newName, const vector<SDL_Rect> &sps, bool _isAnimated);
};

#endif