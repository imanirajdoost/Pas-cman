//
// Created by iman on 10/03/23.
//


#include "header/controller/ScoreController.h"
#include "header/view/ViewManager.h"

ScoreController::ScoreController(): playerScore{0} {

}

void ScoreController::addScore(int scoreToAdd) {
    playerScore += scoreToAdd;
    ViewManager::writeScore(playerScore);
}