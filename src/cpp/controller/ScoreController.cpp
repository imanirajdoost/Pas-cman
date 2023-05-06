

#include <iostream>
#include "header/controller/ScoreController.h"
#include "header/view/TextViewController.h"

ScoreController::ScoreController(shared_ptr<TextViewController> tController, shared_ptr<DataController> dController): playerScore{0} {
    textViewController = std::move(tController);
    dataController = std::move(dController);
}

void ScoreController::addScore(int scoreToAdd) {
    playerScore += scoreToAdd;
    textViewController->writeScore(playerScore);
}

void ScoreController::updateHighscore() {
    if (playerScore > dataController->loadHighscore()) {
        dataController->saveHighscore(playerScore);
        textViewController->writeHighScore(playerScore);
    }
}

int ScoreController::getHighscore() {
    return dataController->loadHighscore();
}