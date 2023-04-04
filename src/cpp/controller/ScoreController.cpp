//
// Created by iman on 10/03/23.
//


#include <iostream>
#include "header/controller/ScoreController.h"
#include "header/view/TextViewController.h"

ScoreController::ScoreController(std::shared_ptr<TextViewController> tController): playerScore{0} {
    textViewController = std::move(tController);
}

void ScoreController::addScore(int scoreToAdd) {
    playerScore += scoreToAdd;
    textViewController->writeScore(playerScore);
}