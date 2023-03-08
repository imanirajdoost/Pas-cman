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
        int PLAYER_MOVE_THRESHOLD = 0;
        MoveDirection direction = MoveDirection::NONE;
        MoveDirection lastDirection = MoveDirection::NONE;
        MoveDirection moveIntent = MoveDirection::NONE;

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
        SDL_Rect getNextStepRect(MoveDirection dir);
        void controlMove();
        void resetMoveDirection();

        SDL_Rect getNextPos() const;
        void setNextPos(const MoveDirection& direction);
        void resetNextPos();
        virtual void move();

        MoveDirection getMoveIntent() const;
        void setMoveIntent(const MoveDirection& direction);
};

#endif