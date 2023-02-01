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
        static int collisionMatrix[7][7];
};