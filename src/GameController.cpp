#include "GameController.h"

#include <iostream>

using namespace std;

vector<shared_ptr<DotSmall>> GameController::spawnDotObjects() {
    auto map = Map::map;

    vector<shared_ptr<DotSmall>> smallDots;

    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            smallDots.push_back(spawnDotSmall(32, 32));
//            if(map[i][j] == MTYPE::ITEM)
//                cout << "* ";
//            else
//                cout << "- ";
        }
        cout << endl;
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
    return dotSmall;
}