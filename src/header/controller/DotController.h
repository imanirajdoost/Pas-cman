//
// Created by iman on 10/03/23.
//

#ifndef PAS_CMAN_DOTCONTROLLER_H
#define PAS_CMAN_DOTCONTROLLER_H

#include <vector>
#include <memory>
#include "header/model/component/EatableComponent.h"
#include "header/model/eatable/DotSmall.h"
#include "header/model/eatable/DotBig.h"
#include "PauseController.h"
#include "header/view/TextViewController.h"

using namespace std;

class DotController {
public:
    explicit DotController(shared_ptr<PauseController> pController, shared_ptr<TextViewController> tController);

    vector<shared_ptr<Dot>> dots;

    shared_ptr<DotSmall> spawnDotSmall(int x, int y);

    vector<shared_ptr<Dot>> spawnDotObjects();

    shared_ptr<DotBig> spawnDotBig(int x, int y);

    bool deleteDot(const Dot &dot);

    bool isBigDot(int i, int j);

private:

    shared_ptr<PauseController> pauseController;
    shared_ptr<TextViewController> textViewController;

    short dotIndex = 0;
    const int bigDotPositions[4][2] = {
            {3,  1},
            {3,  19},
            {20, 1},
            {20, 19}
    };
};


#endif //PAS_CMAN_DOTCONTROLLER_H
