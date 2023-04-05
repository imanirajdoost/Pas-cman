//
// Created by iman on 05/04/23.
//

#include "header/controller/PauseController.h"

PauseController::PauseController(shared_ptr <TimeController> tController) : isPaused(false) {
    timeController = std::move(tController);
}

bool PauseController::hasPaused() const {
    return isPaused;
}

void PauseController::pause() {
    isPaused = true;
}

void PauseController::resume() {
    isPaused = false;
}

void PauseController::pauseFor(long milliSec) {
    pause();
    pauseTime = milliSec;
}

void PauseController::tick() {

    if (pauseTime > 0) {
        pauseTime -= timeController->getLastFrameTime();
        if(pauseTime < 0) {
            resume();
            pauseTime = 0;
        }
    }
}
