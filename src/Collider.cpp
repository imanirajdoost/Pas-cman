#include "../include/Collider.h"

void Collider::setType(const MTYPE& typeToSet) {
    type = typeToSet;
}
MTYPE Collider::getType() const {
    return type;
}

void Collider::setRect(const SDL_Rect& rectToSet) {
    rect = rectToSet;
}
SDL_Rect Collider::getRect() {
    return rect;
}