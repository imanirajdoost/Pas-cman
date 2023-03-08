//
// Created by iman on 08/03/23.
//

#include "../../../include/model/component/HealthComponent.h"

void HealthComponent::die() {
    // @todo implement dying
    _health--;

    if (_health <= 0) {
        gameOver();
    }
}

void HealthComponent::gameOver() {
    // @todo show game over UI or reset the game
}

HealthComponent::HealthComponent(short initHealth) : _health{initHealth} {

}

int HealthComponent::getHealth() const {
    return _health;
}