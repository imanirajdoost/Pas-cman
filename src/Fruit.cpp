#include "../include/Fruit.h"
#include "../include/GameVars.h"
#include "../include/GameController.h"

SDL_Rect sp_fruit = { 290,238, 12,13 };

Fruit::Fruit(int x, int y) : Eatable(sp_fruit, x, y){
    rect.x = x;
    rect.y = y;

    rect.w = TILESIZE;
    rect.h = TILESIZE;
}

void Fruit::getEaten(const Eatable &eatable) {
    if (GameController::deleteBonus(eatable, 200))
        isEaten = true;
}
