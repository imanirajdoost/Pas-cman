//
// Created by iman on 08/03/23.
//

#include "header/model/component/HealthComponent.h"

void HealthComponent::die() {
    // @todo implement dying
    _health--;
}

HealthComponent::HealthComponent(short initHealth) : _health{initHealth} {

}

short HealthComponent::getHealth() const {
    return _health;
}