
#include "header/model/component/HealthComponent.h"

short HealthComponent::die() {
    _health--;
    return _health;
}

HealthComponent::HealthComponent(short initHealth) : _health{initHealth} {

}

short HealthComponent::getHealth() const {
    return _health;
}