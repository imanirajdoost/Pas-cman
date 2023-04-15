#include <utility>
#include <iostream>

#include "header/controller/PauseController.h"

PauseController::PauseController(shared_ptr <TimeController> tController) : isPaused(false) {
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
    std::cout << "resuming" << std::endl;
    if(resumeCallback != nullptr) {
        resumeCallback();
        std::cout << "resuming callback" << std::endl;
    }
}

void PauseController::pauseFor(long milliSec, function<void()> callback) {
    pause();
    resumeCallback = std::move(callback);
    pauseTime = milliSec;
}

void PauseController::tick() {

    if(isPaused) {
        if (pauseTime > 0) {
            pauseTime -= timeController->getLastFrameTime();
            if (pauseTime < 0) {
                resume();
                pauseTime = 0;
            }
        }
    }
}
