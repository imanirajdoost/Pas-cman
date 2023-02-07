#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <memory>
#include "DotSmall.h"
#include "Map.h"

using namespace std;

class GameController {
public:

    static int animationCounter;
    static void spawnGameObject(const MTYPE& objToSpawn, int x, int y);
//    static GameObject spawnGameObject(const MTYPE& objToSpawn,int x, int y);
    static shared_ptr<DotSmall> spawnDotSmall(int x, int y);
    static vector<shared_ptr<DotSmall>> spawnDotObjects();
};



#endif // GAMECONTROLLER_H
