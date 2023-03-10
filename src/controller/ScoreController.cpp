//
// Created by iman on 10/03/23.
//

#include "controller/ScoreController.h"
#include "view/ViewManager.h"

ScoreController::ScoreController(): playerScore{0} {

}

void ScoreController::addScore(int scoreToAdd) {
    playerScore += scoreToAdd;
    ViewManager::writeScore(playerScore);
}