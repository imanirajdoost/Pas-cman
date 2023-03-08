//
// Created by iman on 08/03/23.
//

#include <SDL2/SDL_rect.h>
#include "../../../include/model/component/TransformComponent.h"

void TransformComponent::setPos(int x, int y) {
    rect.x = x;
    rect.y = y;
}

int TransformComponent::getX() const{
    return rect.x;
}

int TransformComponent::getY() const{
    return rect.y;
}

void TransformComponent::setX(int x) {
    rect.x = x;
}

void TransformComponent::setY(int y) {
    rect.y = y;
}

SDL_Rect TransformComponent::getRect() const {
    return rect;
}

TransformComponent::TransformComponent() {

}
