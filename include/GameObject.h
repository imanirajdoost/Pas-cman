#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL.h>

class GameObject {

protected:
    SDL_Rect rect;
    SDL_Rect getRect() const;

    SDL_Rect _r_sprite;
    SDL_Rect _l_sprite;
    SDL_Rect _d_sprite;
    SDL_Rect _u_sprite;
    
    int _animationCounter = 0;
};

#endif