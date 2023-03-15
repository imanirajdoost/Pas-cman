//
// Created by iman on 10/03/23.
//

#ifndef PAS_CMAN_FRUITCONTROLLER_H
#define PAS_CMAN_FRUITCONTROLLER_H


#include "header/model/eatable/Fruit.h"

class FruitController {
public:
    FruitController();

    Fruit fruit;

    bool deleteFruit(const EatableComponent &eatable, int score);

    void initBonusTimer();

private:
    void spawnFruit();

    void resetFruitPosition();
};


#endif //PAS_CMAN_FRUITCONTROLLER_H
