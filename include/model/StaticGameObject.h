#ifndef STATICGAMEOBJECT_H
#define STATICGAMEOBJECT_H

#include "model/GameObject.h"

class StaticGameObject : public GameObject {
public:
    explicit StaticGameObject(SDL_Rect defaultSprite);
    void setPos(int x, int y);

};

#endif