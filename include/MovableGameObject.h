#ifndef MOVABLEGAMEOBJECT_H
#define MOVABLEGAMEOBJECT_H

#include "GameObject.h"
#include "Map.h"
#include <memory>

enum class MoveDirection
{   
    NONE = 0,
    UP = 1, 
    DOWN = 2, 
    LEFT = 3,
    RIGHT = 4
};

class MovableGameObject : public GameObject {

    protected:
        SDL_Rect _next_pos;
        int speed = 4;
        MoveDirection direction = MoveDirection::NONE;
        MoveDirection lastDirection = MoveDirection::NONE;

    public:
        explicit MovableGameObject(SDL_Rect defaultSprite);

        int getX() const;
        int getY() const;
        void setX(int x);
        void setY(int Y);
        int getSpeed() const;
        MoveDirection getMoveDirection() const;
        void setMoveDirection(const MoveDirection& newDirection);
        void setDirectionSprite(const MoveDirection& newDirection);
        void resetMoveDirection();

        SDL_Rect getNextPos() const;
        virtual void setNextPos(const std::vector<std::vector<MTYPE>>& map, const MoveDirection& direction) = 0;
        void resetNextPos();
        virtual void move();
};

#endif