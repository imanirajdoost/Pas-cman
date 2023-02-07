#include "../include/GameController.h"

#include <iostream>
#include <memory>
#include "../include/DotSmall.h"

using namespace std;

void GameController::spawnDotObjects() {
    auto map = Map::map;

    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            // cout << static_cast<int>(map[i][j]) << " ";
            if(map[i][j] == MTYPE::ITEM)
                cout << "* ";
            else
                cout << "- ";
        }
        cout << endl;
    }
}

void GameController::spawnGameObject(const MTYPE& objToSpawn) {
    switch (objToSpawn) {
        case MTYPE::ITEM:
            auto dotSmall = make_unique<DotSmall>();
            dotSmall.setPos();
            break;
        default:
            break;
    }
}