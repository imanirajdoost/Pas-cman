#ifndef GHOST_H
#define GHOST_H

#include <SDL.h>
#include "MovableGameObject.h"
#include "Map.h"

class Ghost: public MovableGameObject {
    protected: 
    bool isVulnerable = false;
    
    public:
    Ghost(int x, int y);
    
};

class Blinky: public Ghost {
    public:
        Blinky(int x, int y);
        void setNextPos(const std::vector<std::vector<MTYPE>>& map, const MoveDirection& direction) override;
private:
    static SDL_Rect blinky_r1;
    static SDL_Rect blinky_r2;
    static SDL_Rect blinky_l1;
    static SDL_Rect blinky_l2;
    static SDL_Rect blinky_d1;
    static SDL_Rect blinky_d2;
    static SDL_Rect blinky_u1;
    static SDL_Rect blinky_u2;
};

class Pinky: public Ghost {
    public:
        Pinky(int x, int y);
        void setNextPos(const std::vector<std::vector<MTYPE>>& map, const MoveDirection& direction) override;
private:
    static SDL_Rect pinky_r1;
    static SDL_Rect pinky_r2;
    static SDL_Rect pinky_l1;
    static SDL_Rect pinky_l2;
    static SDL_Rect pinky_d1;
    static SDL_Rect pinky_d2;
    static SDL_Rect pinky_u1;
    static SDL_Rect pinky_u2;
};

class Inky: public Ghost {
    public:
        Inky(int x, int y);
        void setNextPos(const std::vector<std::vector<MTYPE>>& map, const MoveDirection& direction) override;
private:
    static SDL_Rect inky_r1;
    static SDL_Rect inky_r2;
    static SDL_Rect inky_l1;
    static SDL_Rect inky_l2;
    static SDL_Rect inky_d1;
    static SDL_Rect inky_d2;
    static SDL_Rect inky_u1;
    static SDL_Rect inky_u2;
};

class Clyde: public Ghost {
    public:
        Clyde(int x, int y);
        void setNextPos(const std::vector<std::vector<MTYPE>>& map, const MoveDirection& direction) override;
private:
    static SDL_Rect clyde_r1;
    static SDL_Rect clyde_r2;
    static SDL_Rect clyde_l1;
    static SDL_Rect clyde_l2;
    static SDL_Rect clyde_d1;
    static SDL_Rect clyde_d2;
    static SDL_Rect clyde_u1;
    static SDL_Rect clyde_u2;
};

#endif