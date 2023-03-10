

#include <SDL2/SDL_rect.h>
#include "../../../include/model/eatable/Fruit.h"

SDL_Rect sp_fruit = {290, 238, 12, 13 };

Fruit::Fruit(int x, int y) : EatableComponent(sp_fruit, x, y){
    rect.x = x;
    rect.y = y;

    rect.w = TILESIZE;
    rect.h = TILESIZE;
}

void Fruit::getEaten(const EatableComponent &eatable) {
    if (GameController::deleteBonus(eatable, 200))
        isEaten = true;
}
