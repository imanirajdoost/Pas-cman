#include <stdexcept>
#include <iostream>
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
    bool found = std::any_of(bigDotPositions.begin(), bigDotPositions.end(),
                             [i, j](const auto& dot) {
                                 return dot[0] == i && dot[1] == j;
                             });
    return found;
}

void DotController::deleteDot(const Dot &dot) {
    for (auto i = dots.begin(); i < dots.end(); ++i) {
        if (dot.getIndex() == i->get()->getIndex()) {
            //TODO: remove this
            if(dot.getDotType() == DotType::BIG)
                ghostController->changeMode(Mode::FRIGHTENED);
            dots.erase(i);
//            cout << " remaining dots: " << dots.size() << endl;
            if (dots.empty()) {
                if (gameOverFunction != nullptr)
                    gameOverFunction(true);
            }
        }
    }
}

void DotController::reset_state() {
    dots.clear();
    dots = spawnDotObjects();
}
