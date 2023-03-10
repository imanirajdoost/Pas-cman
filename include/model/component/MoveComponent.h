//
// Created by iman on 08/03/23.
//

#ifndef PAS_CMAN_MOVECOMPONENT_H
#define PAS_CMAN_MOVECOMPONENT_H

#include <vector>
#include "TransformComponent.h"
#include "Map.h"

enum class MoveDirection {
    NONE = 0,
    UP = 1,
    DOWN = 2,
    LEFT = 3,
    RIGHT = 4
};

class MoveComponent : public TransformComponent {
protected:
    SDL_Rect _next_pos;
    int speed = 4;
    MoveDirection direction = MoveDirection::NONE;
    MoveDirection lastDirection = MoveDirection::NONE;

public:
    MoveComponent();

    int getSpeed() const;

    MoveDirection getMoveDirection() const;

    void setMoveDirection(const MoveDirection &newDirection);

    void setDirectionSprite(const MoveDirection &newDirection);

    void resetMoveDirection();

    SDL_Rect getNextPos() const;

    virtual void setNextPos(const std::vector<std::vector<MTYPE>> &map, const MoveDirection &direction) = 0;

    void resetNextPos();

    virtual void move();

};


#endif //PAS_CMAN_MOVECOMPONENT_H
