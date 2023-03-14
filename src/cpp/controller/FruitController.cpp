//
// Created by iman on 10/03/23.
//

#include <random>
#include <iostream>
#include "../../header/controller/FruitController.h"
#include "../../header/GameVars.h"

FruitController::FruitController() {
}


bool FruitController::deleteFruit(const EatableComponent& eatable, int score) {
    if(!eatable.hasBeenEaten()) {
        resetFruitPosition();
        cout << "Adding score: " << score << endl;
        //@TODO
//        addScore(score);
    }
}

void FruitController::initBonusTimer() {

//    int min = 2;
//    int max = 5;
//
////    short spawnTimes = 10;
//
//    // NOTE: Initialise. Do this once (not for every random number).
//    std::default_random_engine rng(std::random_device{}());
//    std::uniform_int_distribution<int> dist(min, max);
//
//    int random_num;
//
//    do {
//        random_num = dist(rng);
//        std::cout << "Rand: " << random_num << std::endl;
//
//        // start counter with current second
//        time_t counter = time(nullptr);
//
//        while(!hasQuit()) {
//            // wait
//            if(time(nullptr) - counter > random_num)
//                break;
//        }
//        if(hasQuit())
//            return;
//
////        std::this_thread::sleep_for(std::chrono::milliseconds (random_num));
//
//        spawnFruit();
////        spawnTimes--;
//
////        std::this_thread::sleep_for(std::chrono::milliseconds (5000ms));
//        int waitTime = 5;
//        counter = time(nullptr);
//        while(!hasQuit()) {
//            // wait
//            if(time(nullptr) - counter > waitTime)
//                break;
//        }
//        if(hasQuit())
//            return;
//
//        resetFruitPosition();
//
//    } while (!hasQuit());
}

void FruitController::spawnFruit() {
    fruit.setPos(10 * TILESIZE, 15 * TILESIZE);
    std::cout << "spawning fruit" << std::endl;
}

void FruitController::resetFruitPosition() {
    fruit.setPos(-100, -100);
}