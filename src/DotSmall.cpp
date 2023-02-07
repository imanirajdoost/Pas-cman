#include "DotSmall.h"

SDL_Rect sp_dot_small = { 4,81, 2,2 };

DotSmall::DotSmall(int x, int y) : Dot(x, y){
    rect.x = x;
    rect.y = y;

    _r_sprite = sp_dot_small;
}