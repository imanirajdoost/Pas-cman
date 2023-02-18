#include "DotSmall.h"
#include "GameController.h"
#include "Dot.h"

SDL_Rect sp_dot_small = {4, 81, 2, 2};

DotSmall::DotSmall(int x, int y) : Dot(x, y) {
    rect.x = x;
    rect.y = y;

    rect.w = smallDotHeight;
    rect.h = smallDotHeight;

    current_sp = make_shared<SDL_Rect>(sp_dot_small);
//    _r_sprite = sp_dot_small;
}

int DotSmall::getRectHeight() {
    return smallDotHeight;
}

void DotSmall::getEaten(const Dot &dot) {
    if (GameController::deleteObject(dot, 10))
        isEaten = true;
}
