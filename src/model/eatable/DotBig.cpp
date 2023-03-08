#include <SDL2/SDL_rect.h>
#include "../../../include/model/eatable/DotBig.h"
#include "../../../include/controller/GameController.h"

SDL_Rect sp_dot_big = { 9,79, 7,7 };

//DotBig::DotBig(int x, int y) : EatableComponent(sp_dot_big, x, y) {
//    rect.x = x;
//    rect.y = y;
//
//    rect.w = bigDotHeight;
//    rect.h = bigDotHeight;
//
//    current_sp = make_shared<SDL_Rect>(sp_dot_big);
//}

//int DotBig::getRectHeight() {
//    return bigDotHeight;
//}
//
//void DotBig::getEaten(const EatableComponent &dot) {
//    if(GameController::deleteDot(dot, 100))
//        isEaten = true;
//}
