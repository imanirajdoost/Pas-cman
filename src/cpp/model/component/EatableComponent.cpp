#include "header/model/component/EatableComponent.h"

EatableComponent::EatableComponent() {
    index = -1;
}

void EatableComponent::setIndex(const short indexToSet) {
    this->index = indexToSet;
}

short EatableComponent::getIndex() const {
    return this->index;
}
