#include "../include/Eatable.h"

Eatable::Eatable(SDL_Rect defaultSprite, int x, int y) : StaticGameObject(defaultSprite) {
    rect.x = x;
    rect.y = y;

    isEaten = false;
}

void Eatable::setIndex(const u_short indexToSet) {
    this->index = indexToSet;
}

u_short Eatable::getIndex() const {
    return this->index;
}

bool Eatable::hasBeenEaten() const {
    return isEaten;
}
