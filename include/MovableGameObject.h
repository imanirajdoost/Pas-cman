#ifndef MOVABLEGAMEOBJECT_H
#define MOVABLEGAMEOBJECT_H

#include "GameObject.h"
#include "Map.h"

enum moveDirection 
{   
    none = 0,
    up = 1, 
    down = 2, 
    left = 3,
    right = 4
};

class MovableGameObject : public GameObject {
    private:
        SDL_Rect * _sprite_in = nullptr;

    protected:
        SDL_Rect _next_pos;

    public:
        int getX();
        int getY();
        SDL_Rect getRect();
        void setX(int x);
        void setY(int Y);
        void draw(SDL_Surface* plancheSprites, SDL_Surface *win_surf);
        SDL_Rect getNextPos();
        virtual void setNextPos(Map map) {};
        void resetNextPos();
        void move();
};

#endif