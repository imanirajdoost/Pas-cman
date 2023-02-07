#include "GameController.h"

#include <iostream>
#include <memory>
#include "DotSmall.h"

using namespace std;

void GameController::spawnDotObjects() {
    auto map = Map::map;

    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            spawnGameObject(MTYPE::ITEM, 32, 32);
//            if(map[i][j] == MTYPE::ITEM)
//                cout << "* ";
//            else
//                cout << "- ";
        }
        cout << endl;
    }
}

void GameController::spawnGameObject(const MTYPE& objToSpawn, int x, int y) {
    switch (objToSpawn) {
        case MTYPE::ITEM:
            auto dotSmall = make_unique<DotSmall>(x, y);
            dotSmall->setPos(x,y);
            break;
    }
}