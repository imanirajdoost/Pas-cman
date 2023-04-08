//
// Created by iman on 10/03/23.
//

#include <stdexcept>
#include <iostream>
#include "header/controller/DotController.h"
#include "header/model/Map.h"
#include "header/GameVars.h"

DotController::DotController(shared_ptr<PauseController> pController, shared_ptr<TextViewController> tController) {
    pauseController = std::move(pController);
    textViewController = std::move(tController);
    dots = spawnDotObjects();
}

vector<shared_ptr<Dot>> DotController::spawnDotObjects() {

    auto map = Map::map;

    vector<shared_ptr<Dot>> mapDots;

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (map[i][j] == MTYPE::ITEM) {
                if (!isBigDot(i, j))
                    mapDots.push_back(spawnDotSmall(j * TILESIZE + SMALL_DOT_SIZE,
                                                    i * TILESIZE + SMALL_DOT_SIZE));
                else
                    mapDots.push_back(spawnDotBig(j * TILESIZE,
                                                  i * TILESIZE));
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
                // @TODO : Win the game
                cout << "You won !" << endl;
                pauseController->pause();
                textViewController->writeOnUI("you_won","congratulations!", 6 * TILESIZE, 10 * TILESIZE);
            }
            return true;
        }
    }
    return false;
}