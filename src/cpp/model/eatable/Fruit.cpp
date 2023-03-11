#include <SDL2/SDL_rect.h>
#include "../../../header/model/eatable/Fruit.h"
#include "../../../header/GameVars.h"

void Fruit::getEaten(const EatableComponent &eatable) {
    if (GameController::deleteBonus(eatable, 200))
        isEaten = true;
}

Fruit::Fruit() {
    setPos(0, 0);
    setSize(TILESIZE, TILESIZE);

    current_sp = std::make_shared<SDL_Rect>(sp_fruit);
}
