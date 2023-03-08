#include "controller/GameController.h"

#include <iostream>
#include "GameVars.h"
#include "model/eatable/DotBig.h"
#include "view/ViewManager.h"

#include <chrono>
#include <thread>
#include <random>

using namespace std;

int GameController::animationCounter = 0;
uint GameController::playerScore = 0;
std::vector<shared_ptr<EatableComponent>> GameController::dots;

Fruit GameController::fruit {-100,-100};

bool GameController::exit = false;

int GameController::bigDotPositions[4][2] = {
        {3,  1},
        {3,  19},
        {20, 1},
        {20, 19}
};

u_short GameController::dotIndex = 0;

void GameController::initItems() {
    GameController::dots = spawnDotObjects();
}

vector<shared_ptr<EatableComponent>> GameController::spawnDotObjects() {

    auto map = Map::map;

    vector<shared_ptr<EatableComponent>> mapDots;

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (map[i][j] == MTYPE::ITEM) {
                if (!isBigDot(i, j))
                    mapDots.push_back(spawnDotSmall(j * TILESIZE + DotSmall::getRectHeight(),
                                                    i * TILESIZE + DotSmall::getRectHeight()));
                else
                    mapDots.push_back(spawnDotBig(j * TILESIZE,
                                                  i * TILESIZE));
            }
        }
    }

    return mapDots;
}


//GameObject GameController::spawnGameObject(const MTYPE& objToSpawn, int x, int y) {
//    switch (objToSpawn) {
//        case MTYPE::ITEM:
//            auto dotSmall = make_unique<DotSmall>(x, y);
//            dotSmall->setPos(x,y);
//            return dotSmall;
//            break;
//    }
//}

shared_ptr<DotSmall> GameController::spawnDotSmall(int x, int y) {
    auto dotSmall = make_shared<DotSmall>(x, y);
    dotSmall->setPos(x, y);
    dotSmall->setIndex(GameController::dotIndex++);
    return dotSmall;
}

shared_ptr<DotBig> GameController::spawnDotBig(int x, int y) {
    auto dotBig = make_shared<DotBig>(x, y);
    dotBig->setPos(x, y);
    dotBig->setIndex(GameController::dotIndex++);
    return dotBig;
}

void GameController::addScore(uint scoreToAdd) {
    playerScore += scoreToAdd;
    ViewManager::writeScore(playerScore);
//    cout << "Score: " << playerScore << endl;
}

bool GameController::deleteDot(const EatableComponent &dot, uint score) {
//    auto targetToDel = dots[dot.getIndex()].get();

    for (auto i = GameController::dots.begin(); i < GameController::dots.end(); ++i) {
        if (dot.getIndex() == i->get()->getIndex() && !dot.hasBeenEaten()) {
            GameController::dots.erase(i);
            addScore(score);
//            cout << " remaining dots: " << GameController::dots.size() << endl;
            if (GameController::dots.empty()) {
                // @TODO : Win the game
                cout << "You won !" << endl;
            }
            return true;
        }
    }
    return false;

//    if(!dot.hasBeenEaten())
//        GameController::dots.erase(GameController::dots.begin() + dot.getIndex());
}

bool GameController::deleteBonus(const EatableComponent& eatable, uint score) {
    if(!eatable.hasBeenEaten()) {
        resetFruitPosition();
        addScore(score);
    }
}

bool GameController::isBigDot(int i, int j) {
    if (Map::map[i][j] != MTYPE::ITEM) {
        cout << "FATAL ERROR : Big dot position is not valid: " << i << ", " << j << endl;
        throw invalid_argument("i or j values are not valid");
    }
    for (auto dot: bigDotPositions) {
        if (dot[0] == i && dot[1] == j)
            return true;
    }
    return false;
}

void GameController::initBonusTimer() {

    int min = 2;
    int max = 5;

//    short spawnTimes = 10;

    // NOTE: Initialise. Do this once (not for every random number).
    std::default_random_engine rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(min, max);

    int random_num;

    do {
        random_num = dist(rng);
        cout << "Rand: " << random_num << endl;

        // start counter with current second
        time_t counter = time(nullptr);

        while(!hasQuit()) {
            // wait
            if(time(nullptr) - counter > random_num)
                break;
        }
        if(hasQuit())
            return;

//        std::this_thread::sleep_for(std::chrono::milliseconds (random_num));

        spawnFruit();
//        spawnTimes--;

//        std::this_thread::sleep_for(std::chrono::milliseconds (5000ms));
        int waitTime = 5;
        counter = time(nullptr);
        while(!hasQuit()) {
            // wait
            if(time(nullptr) - counter > waitTime)
                break;
        }
        if(hasQuit())
            return;

        resetFruitPosition();

    } while (!hasQuit());
}

void GameController::spawnFruit() {
    fruit.setPos(10 * TILESIZE, 15 * TILESIZE);
    cout << "spawning fruit" << endl;
}

void GameController::resetFruitPosition() {
    fruit.setPos(-100, -100);
}

bool GameController::hasQuit() {
    return exit;
}
