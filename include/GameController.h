#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <memory>
#include "DotSmall.h"
#include "Map.h"

using namespace std;

class GameController {
public:
    static std::vector<shared_ptr<DotSmall>> dots;
    static uint playerScore;
    static int animationCounter;
//    static GameObject spawnGameObject(const MTYPE& objToSpawn,int x, int y);
    static shared_ptr<DotSmall> spawnDotSmall(int x, int y);
    static vector<shared_ptr<DotSmall>> spawnDotObjects();
    static void initDots();

    static void addScore(uint scoreToAdd);

    static void deleteObject(const Dot& dot);

private:
    static u_short dotIndex;
};



#endif // GAMECONTROLLER_H
