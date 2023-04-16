//
// Created by iman on 10/03/23.
//

#include <stdexcept>
#include <iostream>
#include "header/controller/DotController.h"
#include "header/model/Map.h"
#include "header/GameVars.h"

DotController::DotController(std::function<void(bool)> _gameOverFunction) {
    gameOverFunction = std::move(_gameOverFunction);
    dots = spawnDotObjects();
}

vector<shared_ptr<Dot>> DotController::spawnDotObjects() {

    auto map = Map::map;

    vector<shared_ptr<Dot>> mapDots;

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (map[i][j] == MTYPE::ITEM) {
                if (!isBigDot(i, j))
                    mapDots.push_back(spawnDotSmall(j * TILESIZE + ((TILESIZE / 2) - (SMALL_DOT_SIZE / 2)),
                                                    i * TILESIZE + (TILESIZE / 2) - (SMALL_DOT_SIZE / 2)));
                else
                    mapDots.push_back(spawnDotBig((j * TILESIZE) + ((TILESIZE / 2) - (BIG_DOT_SIZE / 2)),
                                                  (i * TILESIZE) + (TILESIZE / 2) - (BIG_DOT_SIZE / 2)));
            }
        }
    }

    return mapDots;
}

shared_ptr<DotSmall> DotController::spawnDotSmall(int x, int y) {
    auto dotSmall = make_shared<DotSmall>();
    dotSmall->setPos(x, y);
    dotSmall->setIndex(dotIndex++);
    return dotSmall;
}

shared_ptr<DotBig> DotController::spawnDotBig(int x, int y) {
    auto dotBig = make_shared<DotBig>();
    dotBig->setPos(x, y);
    dotBig->setIndex(dotIndex++);
    return dotBig;
}

bool DotController::isBigDot(int i, int j) {
    if (Map::map[i][j] != MTYPE::ITEM) {
        std::cout << "FATAL ERROR : Big dot position is not valid: " << i << ", " << j << std::endl;
        throw invalid_argument("i or j values are not valid");
    }
    for (auto dot: bigDotPositions) {
        if (dot[0] == i && dot[1] == j)
            return true;
    }
    return false;
}

bool DotController::deleteDot(const Dot &dot) {
    for (auto i = dots.begin(); i < dots.end(); ++i) {
        if (dot.getIndex() == i->get()->getIndex()) {
            dots.erase(i);
//            cout << " remaining dots: " << dots.size() << endl;
            if (dots.empty()) {
//            if (dots.size() < 180) {
                if (gameOverFunction != nullptr)
                    gameOverFunction(true);
            }
            return true;
        }
    }
    return false;
}