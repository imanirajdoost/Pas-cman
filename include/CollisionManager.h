#include "Map.h"

#include <SDL.h>

class CollisionManager {

    public:
enum COLOBJ {
    PACMAN,
    GHOST,
    WALL,
    COIN,
    TP,
    DOOR, 
    EMPTY
};

        template <typename T>
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