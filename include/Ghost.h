#ifndef GHOST_H
#define GHOST_H

#include <SDL.h>
#include "MovableGameObject.h"
#include "Map.h"

extern SDL_Rect blinky_r; 
extern SDL_Rect blinky_l; 
extern SDL_Rect blinky_d; 
extern SDL_Rect blinky_u;

extern SDL_Rect pinky_r; 
extern SDL_Rect pinky_l; 
extern SDL_Rect pinky_d;
extern SDL_Rect pinky_u;

extern SDL_Rect inky_r; 
extern SDL_Rect inky_l; 
extern SDL_Rect inky_d; 
extern SDL_Rect inky_u;

extern SDL_Rect clyde_r; 
extern SDL_Rect clyde_l; 
extern SDL_Rect clyde_d; 
extern SDL_Rect clyde_u;


class Ghost: public MovableGameObject {
    protected: 
    bool isVulnerable = false;
    
    public:
    Ghost(int x, int y);
    
};

class Blinky: public Ghost {
    public:
        Blinky(int x, int y);
        void setNextPos(const MTYPE[27][21], const MoveDirection& direction) override;
};

class Pinky: public Ghost {
    public:
        Pinky(int x, int y);
        void setNextPos(const MTYPE[27][21], const MoveDirection& direction) override;
};

class Inky: public Ghost {
    public:
        Inky(int x, int y);
        void setNextPos(const MTYPE[27][21], const MoveDirection& direction) override;
};

class Clyde: public Ghost {
    public:
        Clyde(int x, int y);
        void setNextPos(const MTYPE[27][21], const MoveDirection& direction) override;
};

#endif