#include "GameController.h"

#include <iostream>
#include "GameVars.h"
#include "DotBig.h"

using namespace std;

int GameController::animationCounter = 0;
uint GameController::playerScore = 0;
std::vector<shared_ptr<Dot>> GameController::dots;

int GameController::bigDotPositions[4][2] = {
        {3,  1},
        {3,  19},
        {20, 1},
        {20, 19}
};

u_short GameController::dotIndex = 0;

void GameController::initDots() {
    GameController::dots = spawnDotObjects();
}

vector<shared_ptr<Dot>> GameController::spawnDotObjects() {

    auto map = Map::map;

    vector<shared_ptr<Dot>> mapDots;

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
    cout << "Score: " << playerScore << endl;
}

bool GameController::deleteObject(const Dot &dot, uint score) {
//    auto targetToDel = dots[dot.getIndex()].get();

    for (auto i = GameController::dots.begin(); i < GameController::dots.end(); ++i) {
        if (dot.getIndex() == i->get()->getIndex() && !dot.hasBeenEaten()) {
            GameController::dots.erase(i);
            GameController::addScore(score);
            return true;
        }
    }
    return false;

//    if(!dot.hasBeenEaten())
//        GameController::dots.erase(GameController::dots.begin() + dot.getIndex());
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
