#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <memory>
#include "model/eatable/DotSmall.h"
#include "Map.h"
#include "model/eatable/DotBig.h"
#include "model/eatable/Fruit.h"

using namespace std;

class GameController {
public:
     bool exit;
     Fruit fruit;
     std::vector<shared_ptr<EatableComponent>> dots;
    static uint playerScore;
    static int animationCounter;
    static shared_ptr<DotSmall> spawnDotSmall(int x, int y);
    static vector<shared_ptr<EatableComponent>> spawnDotObjects();
    static shared_ptr<DotBig> spawnDotBig(int x, int y);
    static bool deleteBonus(const EatableComponent &eatable, uint score);
    static void initItems();
    static void addScore(uint scoreToAdd);
    static bool deleteDot(const EatableComponent& dot, uint score);
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
