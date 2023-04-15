//
// Created by iman on 10/03/23.
//

#include <random>
#include <iostream>
#include "header/controller/FruitController.h"
#include "header/GameVars.h"

FruitController::FruitController(shared_ptr<TimeController> tController) {
    resetFruitPosition();
    last_time_fruit_spawned = 0;
    fruitAvailable = false;

    timeController = std::move(tController);
}

bool FruitController::deleteFruit() {
    resetFruitPosition();
    return true;
}

void FruitController::spawnFruit() {
    fruit.setPos(10 * TILESIZE, 15 * TILESIZE);
//    std::cout << "spawning fruit" << std::endl;
    fruitAvailable = true;
}

void FruitController::resetFruitPosition() {
    fruit.setPos(-100, -100);
    fruitAvailable = false;
}

void FruitController::tick() {
    ulong elapsed_time = timeController->getElapsedTime();
    if(!fruitAvailable && elapsed_time > MIN_TIME_TO_SPAWN_FRUIT && (elapsed_time - last_time_fruit_spawned) >= FRUIT_SPAWN_TIME) {
        last_time_fruit_spawned = elapsed_time;
        spawnFruit();
    }

    if(fruitAvailable && (elapsed_time - last_time_fruit_spawned) >= FRUIT_AVAILABE_TIME) {
        elapsed_time = last_time_fruit_spawned;
        resetFruitPosition();
    }
}


