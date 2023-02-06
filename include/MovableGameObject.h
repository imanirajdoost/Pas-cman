#ifndef MOVABLEGAMEOBJECT_H
#define MOVABLEGAMEOBJECT_H

#include "GameObject.h"
#include "Map.h"

enum class MoveDirection
{   
    NONE = 0,
    UP = 1, 
    DOWN = 2, 
    LEFT = 3,
    RIGHT = 4
};

class MovableGameObject : public GameObject {
    private:
        SDL_Rect * _sprite_in = nullptr;

    protected:
        SDL_Rect _next_pos;
        int speed = 4;
        MoveDirection direction = MoveDirection::NONE;

    public:
        int getX() const;
        int getY() const;
        SDL_Rect getRect() const;
        void setX(int x);
        void setY(int Y);
        MoveDirection getMoveDirection() const;
        void setMoveDirection(const MoveDirection& newDirection);

        void draw(SDL_Surface* plancheSprites, SDL_Surface* win_surf);
        SDL_Rect getNextPos() const;
        virtual void setNextPos(const MTYPE map[27][21], const MoveDirection& direction) = 0;
        void resetNextPos();
        void move();
};

#endif