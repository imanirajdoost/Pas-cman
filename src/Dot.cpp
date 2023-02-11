#include "Dot.h"

Dot::Dot(int x, int y)  {
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
