#include "../../../header/model/component/EatableComponent.h"

EatableComponent::EatableComponent() {
    isEaten = false;
}

void EatableComponent::setIndex(const short indexToSet) {
    this->index = indexToSet;
}

short EatableComponent::getIndex() const {
    return this->index;
}

bool EatableComponent::hasBeenEaten() const {
    return isEaten;
}

void EatableComponent::getEaten(const EatableComponent &dot, int score) {

}

//void EatableComponent::getEaten(const EatableComponent &dot) {
//    if(GameController::deleteDot(dot, 100))
//        isEaten = true;
//}
