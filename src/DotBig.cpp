#include <SDL2/SDL_rect.h>
#include "../include/DotBig.h"
#include "../include/GameController.h"

SDL_Rect sp_dot_big = { 9,79, 7,7 };

DotBig::DotBig(int x, int y) : Dot(SDL_Rect(), x, y) {
    rect.x = x;
    rect.y = y;

    rect.w = bigDotHeight;
    rect.h = bigDotHeight;

    current_sp = make_shared<SDL_Rect>(sp_dot_big);
//    _r_sprite = sp_dot_big;
}

int DotBig::getRectHeight() {
    return bigDotHeight;
}

void DotBig::getEaten(const Dot &dot) {
    if(GameController::deleteObject(dot, 100))
        isEaten = true;
}
