//
// Created by iman on 10/03/23.
//


#include <iostream>
#include "header/controller/ScoreController.h"
#include "header/view/TextViewController.h"

ScoreController::ScoreController(): playerScore{0} {

}

void ScoreController::addScore(int scoreToAdd) {
    playerScore += scoreToAdd;
    cout << "send score to view" << endl;
//    TextViewController::writeScore(playerScore);
}