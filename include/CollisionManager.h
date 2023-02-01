#include <SDL.h>

#include "Map.h"

enum COLOBJ {
    PACMAN,
    GHOST,
    CWALL,
    CCOIN,
    TP,
    CDOOR, 
    CEMPTY
};

class CollisionManager {
    public:
        static bool isCollision(Map map, SDL_Rect targetPos, COLOBJ obj);
        static constexpr int collisionMatrix[7][7] = {
            {0,1,1,1,1,1,0},
            {1,0,1,0,1,0,0},
            {1,1,0,0,0,0,0},
            {1,0,0,0,0,0,0},
            {1,1,0,0,0,0,0},
            {1,0,0,0,0,0,0},
            {0,0,0,0,0,0,0}, 
        };
};