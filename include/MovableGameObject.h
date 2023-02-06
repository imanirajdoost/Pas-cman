#ifndef MOVABLEGAMEOBJECT_H
#define MOVABLEGAMEOBJECT_H

#include "GameObject.h"
#include "Map.h"

enum MoveDirection 
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

    public:
        int getX() const;
        int getY() const;
        SDL_Rect getRect() const;
        void setX(int x);
        void setY(int Y);
        void draw(SDL_Surface* plancheSprites, SDL_Surface* win_surf);
        SDL_Rect getNextPos() const;
        virtual void setNextPos(const Map& map, const MoveDirection& direction) = 0;
        void resetNextPos();
        void move();
};

#endif