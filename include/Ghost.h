#ifndef GHOST_H
#define GHOST_H

#include <SDL.h>

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


class Ghost {
    private:
    int _animationCounter = 0;
    SDL_Rect* _ghost_in = nullptr;

    protected:
    SDL_Rect ghost;
    SDL_Rect _r_sprite;
    SDL_Rect _l_sprite;
    SDL_Rect _d_sprite;
    SDL_Rect _u_sprite;
    
    public:
    Ghost(int x, int y);
    int getX();
    int getY();
    void setX(int x);
    void setY(int Y);
    void draw(SDL_Surface* plancheSprites, SDL_Surface *win_surf);
    void move();
    
};

class Blinky: public Ghost {
    using Ghost::Ghost;
    using Ghost::move;
    public:
        Blinky(int x, int y);
};

class Pinky: public Ghost {
    using Ghost::Ghost;
    using Ghost::move;
    public:
        Pinky(int x, int y);
};

class Inky: public Ghost {
    using Ghost::Ghost;
    using Ghost::move;
    public:
        Inky(int x, int y);
};

class Clyde: public Ghost {
    using Ghost::Ghost;
    using Ghost::move;
    public:
        Clyde(int x, int y);
};

#endif