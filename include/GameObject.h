#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL.h>

class GameObject {
public:
    void draw(SDL_Surface* plancheSprites, SDL_Surface* win_surf);
    SDL_Rect getRect() const;

protected:
    SDL_Rect * _sprite_in = nullptr;
    SDL_Rect rect;

    SDL_Rect _r_sprite;
    SDL_Rect _l_sprite;
    SDL_Rect _d_sprite;
    SDL_Rect _u_sprite;

    bool isAnimated = false;
};

#endif