#include "GameController.h"

#include <iostream>
#include "GameVars.h"

using namespace std;

int GameController::animationCounter = 0;
uint GameController::playerScore = 0;
std::vector<shared_ptr<DotSmall>> GameController::dots;

u_short GameController::dotIndex = 0;

void GameController::initDots() {
    GameController::dots = spawnDotObjects();
}

vector<shared_ptr<DotSmall>> GameController::spawnDotObjects() {

    auto map = Map::map;

    vector<shared_ptr<DotSmall>> smallDots;

    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            if(map[i][j] == MTYPE::ITEM)
                smallDots.push_back(spawnDotSmall(j * TILESIZE + DotSmall::getRectHeight(), i * TILESIZE + DotSmall::getRectHeight()));
        }
    }

    return smallDots;
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
    dotSmall->setPos(x,y);
    dotSmall->setIndex(GameController::dotIndex++);
    return dotSmall;
}

void GameController::addScore(uint scoreToAdd) {
    playerScore += scoreToAdd;
    cout << "Score: " << playerScore << endl;
}

bool GameController::deleteObject(const Dot& dot) {
//    auto targetToDel = dots[dot.getIndex()].get();

    for (auto i = GameController::dots.begin(); i < GameController::dots.end(); ++i) {
        if(dot.getIndex() == i->get()->getIndex() && !dot.hasBeenEaten()) {
            GameController::dots.erase(i);
            GameController::addScore(10);
            return true;
        }
    }
    return false;

//    if(!dot.hasBeenEaten())
//        GameController::dots.erase(GameController::dots.begin() + dot.getIndex());
}
