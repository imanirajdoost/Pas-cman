//
// Created by iman on 10/03/23.
//


#include <iostream>
#include "header/controller/ScoreController.h"
#include "header/view/ViewManager.h"

ScoreController::ScoreController(): playerScore{0} {

}

void ScoreController::addScore(int scoreToAdd) {
    playerScore += scoreToAdd;
    cout << "send score to view" << endl;
//    ViewManager::writeScore(playerScore);
}