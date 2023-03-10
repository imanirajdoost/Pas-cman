#ifndef COLLIDER_H
#define COLLIDER_H

#include <SDL_rect.h>
#include "Map.h"

class Collider {
private:
    MTYPE type;
    SDL_Rect rect;
public:
    void setType(const MTYPE& typeToSet);
    MTYPE getType() const;

    void setRect(const SDL_Rect& rectToSet);
    SDL_Rect getRect();
};


#endif