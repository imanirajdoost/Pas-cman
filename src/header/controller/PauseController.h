//
// Created by iman on 05/04/23.
//

#ifndef PAS_CMAN_PAUSECONTROLLER_H
#define PAS_CMAN_PAUSECONTROLLER_H


#include <memory>
#include "TimeController.h"

using namespace std;

class PauseController {
public:
    explicit PauseController(shared_ptr<TimeController> tController);

    void pause();

    void resume();

    void pauseFor(long milliSec);

    void tick();

    bool hasPaused() const;
private:
    bool isPaused;

    long pauseTime;

    shared_ptr<TimeController> timeController;
};


#endif //PAS_CMAN_PAUSECONTROLLER_H
