#include "DotSmall.h"
#include "GameController.h"
#include "Dot.h"

SDL_Rect sp_dot_small = { 4,81, 2,2 };

DotSmall::DotSmall(int x, int y) : Dot(x, y){
    rect.x = x;
    rect.y = y;

    rect.w = dotHeight;
    rect.h = dotHeight;

    _r_sprite = sp_dot_small;
}

int DotSmall::getRectHeight() {
    return dotHeight;
}

void DotSmall::getEaten(const Dot& dot) {
    if(GameController::deleteObject(dot))
        isEaten = true;
}
