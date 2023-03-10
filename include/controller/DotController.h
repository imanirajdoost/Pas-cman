//
// Created by iman on 10/03/23.
//

#ifndef PAS_CMAN_DOTCONTROLLER_H
#define PAS_CMAN_DOTCONTROLLER_H

#include <vector>
#include "model/eatable/DotSmall.h"
#include "model/eatable/DotBig.h"

using namespace std;

class DotController {
public:
    DotController();

    vector<shared_ptr<EatableComponent>> dots;

    shared_ptr<DotSmall> spawnDotSmall(int x, int y);

    vector<shared_ptr<EatableComponent>> spawnDotObjects();

    shared_ptr<DotBig> spawnDotBig(int x, int y);

    bool deleteDot(const EatableComponent &dot, uint score);

private:
    short dotIndex = 0;
    const int bigDotPositions[4][2] = {
            {3,  1},
            {3,  19},
            {20, 1},
            {20, 19}
    };

    bool isBigDot(int i, int j);
};


#endif //PAS_CMAN_DOTCONTROLLER_H
