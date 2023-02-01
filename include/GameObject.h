#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL.h>

class GameObject {

protected:
    SDL_Rect rect;
    SDL_Rect getRect();
};

#endif