#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Map.h"

class GameController {
public:
    static void spawnDotObjects();
    static void spawnGameObject(const MTYPE& objToSpawn);
};


#endif // GAMECONTROLLER_H
