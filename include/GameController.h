#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Map.h"

class GameController {
public:

    static int animationCounter;

    static void spawnDotObjects();
    static void spawnGameObject(const MTYPE& objToSpawn, int x, int y);
};


#endif // GAMECONTROLLER_H
