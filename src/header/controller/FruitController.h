//
// Created by iman on 10/03/23.
//

#ifndef PAS_CMAN_FRUITCONTROLLER_H
#define PAS_CMAN_FRUITCONTROLLER_H


#include "header/model/eatable/Fruit.h"
#include "TimeController.h"

class FruitController {
public:
    explicit FruitController(shared_ptr<TimeController> tController);

    Fruit fruit;

    bool deleteFruit();

    void tick();

private:
    void spawnFruit();

    void resetFruitPosition();

    shared_ptr<TimeController> timeController;

    bool fruitAvailable;

    long last_time_fruit_spawned;
};


#endif //PAS_CMAN_FRUITCONTROLLER_H
