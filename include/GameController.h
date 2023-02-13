#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <memory>
#include "DotSmall.h"
#include "Map.h"
#include "DotBig.h"

using namespace std;

class GameController {
public:
    static std::vector<shared_ptr<Dot>> dots;
    static uint playerScore;
    static int animationCounter;
    static shared_ptr<DotSmall> spawnDotSmall(int x, int y);
    static vector<shared_ptr<Dot>> spawnDotObjects();
    static shared_ptr<DotBig> spawnDotBig(int x, int y);
    static void initDots();
    static void addScore(uint scoreToAdd);
    static bool deleteObject(const Dot& dot, uint score);

private:
    static u_short dotIndex;
    static int bigDotPositions[4][2];
    static bool isBigDot(int i, int j);
};



#endif // GAMECONTROLLER_H
