#include <stdexcept>
#include <iostream>
#include <algorithm>
#include "header/controller/DotController.h"
#include "header/model/Map.h"
#include "header/GameVars.h"

DotController::DotController(function<void(bool)> gOverFunction, shared_ptr<GhostController> gController) {
    gameOverFunction = std::move(gOverFunction);
    ghostController = std::move(gController);
    dots = spawnDotObjects();
}

vector<shared_ptr<Dot>> DotController::spawnDotObjects() {

    auto map = Map::map;

    vector<shared_ptr<Dot>> mapDots;

    int offsetSmallDot = (TILESIZE / 2) - (SMALL_DOT_SIZE / 2);
    int offsetBigDot = (TILESIZE / 2) - (BIG_DOT_SIZE / 2);

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (map[i][j] == MTYPE::ITEM) {
                if (!isBigDot(i, j))
                    mapDots.push_back(spawnDotSmall(j * TILESIZE + offsetSmallDot,
                                                    i * TILESIZE + offsetSmallDot));
                else
                    mapDots.push_back(spawnDotBig((j * TILESIZE) + offsetBigDot,
                                                  (i * TILESIZE) + offsetBigDot));
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

    // check if the position of the given dot exist in the array of bigDotPositions
    bool found = std::any_of(bigDotPositions.begin(), bigDotPositions.end(),
                             [i, j](const auto& dot) {
                                 return dot[0] == i && dot[1] == j;
                             });
    return found;
}

void DotController::deleteDot(const Dot &dot) {
    auto it = std::find_if(dots.begin(), dots.end(), [&dot](const auto &d) {
        return dot.getIndex() == d->getIndex();
    });

    // If the dot exists
    if (it != dots.end()) {

        // if the type of the dot is "Big"
        if (dot.getDotType() == DotType::BIG) {
            ghostController->changeMode(Mode::FRIGHTENED);
        }

        // remove the dot from the list
        dots.erase(it);

        // if no more dots remain, call the game over function
        if (dots.empty() && gameOverFunction != nullptr) {
            gameOverFunction(true);
        }
    }
}

void DotController::reset_state() {
    dots.clear();
    dots = spawnDotObjects();
}
