#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL.h>

enum moveDirection 
{   
    none = 0,
    up = 1, 
    down = 2, 
    left = 3,
    right = 4
};

class GameObject {

protected:
    SDL_Rect rect;
    SDL_Rect getRect();
};

#endif