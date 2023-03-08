//
// Created by iman on 08/03/23.
//

#include <SDL2/SDL_rect.h>
#include "../../../include/model/component/MoveComponent.h"


MoveDirection MoveComponent::getMoveDirection() const {
    return direction;
}

void MoveComponent::setMoveDirection(const MoveDirection& newDirection) {
    direction = newDirection;
    setDirectionSprite(newDirection);
}

void MoveComponent::resetMoveDirection() {
    setMoveDirection(lastDirection);
}


void MoveComponent::setDirectionSprite(const MoveDirection& newDirection) {
    switch (newDirection) {
        case MoveDirection::DOWN:
            setAnimation("move_down");
//            current_sp = &(_d_sprite);
            break;
        case MoveDirection::UP:
            setAnimation("move_up");
//            current_sp = &(_u_sprite);
            break;
        case MoveDirection::LEFT:
            setAnimation("move_left");
//            current_sp = &(_l_sprite);
            break;
        case MoveDirection::RIGHT:
            setAnimation("move_right");
        default:
//            setAnimation("default");
//            current_sp = make_shared<SDL_Rect>(default_sp);
//            current_sp = &(_r_sprite);
            break;
    }
}


SDL_Rect MoveComponent::getNextPos() const{
    return _next_pos;
}

int MoveComponent::getSpeed() const {
    return speed;
}

void MoveComponent::resetNextPos() {
    _next_pos = rect;
}

void MoveComponent::move() {
    rect.x = _next_pos.x;
    rect.y = _next_pos.y;
}