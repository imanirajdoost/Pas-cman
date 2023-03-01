#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <memory>
#include "DotSmall.h"
#include "Map.h"
#include "DotBig.h"
#include "Fruit.h"

using namespace std;

class GameController {
public:
    static bool exit;
    static Fruit fruit;
    static std::vector<shared_ptr<Eatable>> dots;
    static uint playerScore;
    static int animationCounter;
    static shared_ptr<DotSmall> spawnDotSmall(int x, int y);
    static vector<shared_ptr<Eatable>> spawnDotObjects();
    static shared_ptr<DotBig> spawnDotBig(int x, int y);
    static bool deleteBonus(const Eatable &eatable, uint score);
    static void initItems();
    static void addScore(uint scoreToAdd);
    static bool deleteDot(const Eatable& dot, uint score);
    static void initBonusTimer();

private:
    static u_short dotIndex;
    static int bigDotPositions[4][2];
    static bool isBigDot(int i, int j);

    static void spawnFruit();

    static void resetFruitPosition();

    static bool hasQuit();
};



#endif // GAMECONTROLLER_H
