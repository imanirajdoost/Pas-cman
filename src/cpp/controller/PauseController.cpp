#include <utility>
#include <iostream>

#include "header/controller/PauseController.h"

PauseController::PauseController(shared_ptr<TimeController> tController) : isPaused(false) {
    timeController = std::move(tController);
    pauseTime = 0;
}

bool PauseController::hasPaused() const {
    return isPaused;
}

void PauseController::pause() {
    isPaused = true;
}

void PauseController::resume() {
    isPaused = false;
    if (resumeCallback != nullptr) {
        resumeCallback(callBackBool);
    }
}

void PauseController::pauseFor(long milliSec, function<void(bool)> callback, bool cbackBool) {
    pause();
    resumeCallback = std::move(callback);
    callBackBool = cbackBool;
    pauseTime = milliSec;
}

void PauseController::tick() {

    if (isPaused) {
        if (pauseTime > 0) {
            pauseTime -= timeController->getLastFrameTime();
            if (pauseTime <= 0) {
                resume();
                pauseTime = 0;
            }
        }
    }
}
