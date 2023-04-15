//
// Created by iman on 10/03/23.
//


#include <iostream>
#include "header/controller/ScoreController.h"
#include "header/view/TextViewController.h"

ScoreController::ScoreController(std::shared_ptr<TextViewController> tController, std::shared_ptr<DataController> dController): playerScore{0} {
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
    }
}

int ScoreController::getHighscore() {
    return dataController->loadHighscore();
}