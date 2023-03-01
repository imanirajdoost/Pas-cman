#include "../include/Fruit.h"
#include "../include/GameVars.h"

SDL_Rect sp_fruit = { 290,238, 12,13 };

Fruit::Fruit(int x, int y) : StaticGameObject{sp_fruit} {
    rect.x = x;
    rect.y = y;

    rect.w = TILESIZE;
    rect.h = TILESIZE;
}
