#include "../../../include/model/component/EatableComponent.h"

EatableComponent::EatableComponent(SDL_Rect defaultSprite, int x, int y) : StaticGameObject(defaultSprite) {
    rect.x = x;
    rect.y = y;

    isEaten = false;
}

void EatableComponent::setIndex(const u_short indexToSet) {
    this->index = indexToSet;
}

u_short EatableComponent::getIndex() const {
    return this->index;
}

bool EatableComponent::hasBeenEaten() const {
    return isEaten;
}
