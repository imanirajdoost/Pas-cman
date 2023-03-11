//
// Created by iman on 08/03/23.
//

#include <SDL2/SDL_rect.h>
#include "../../../header/model/component/TransformComponent.h"
#include "../../../header/GameVars.h"


void TransformComponent::setPos(int x, int y) {
    rect.x = x;
    rect.y = y;
}

void TransformComponent::setSize(int x, int y) {
    rect.w = x;
    rect.h = y;
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
    setPos(0,0);
    setSize(TILESIZE, TILESIZE);
}

TransformComponent::TransformComponent(int posX, int posY, int sizeWidth, int sizeHeight) {
    setPos(posX, posY);
    setSize(sizeWidth, sizeHeight);
}
