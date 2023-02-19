#include "Dot.h"

Dot::Dot(SDL_Rect defaultSprite, int x, int y) : StaticGameObject(defaultSprite) {
    rect.x = x;
    rect.y = y;

    isEaten = false;
}

void Dot::setIndex(const u_short indexToSet) {
    this->index = indexToSet;
}

u_short Dot::getIndex() const {
    return this->index;
}

bool Dot::hasBeenEaten() const {
    return isEaten;
}
