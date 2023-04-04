//
// Created by iman on 10/03/23.
//

#ifndef PAS_CMAN_SCORECONTROLLER_H
#define PAS_CMAN_SCORECONTROLLER_H


#include <memory>
#include "header/view/TextViewController.h"

class ScoreController {
public:
    ScoreController(std::shared_ptr<TextViewController> tController);

    void addScore(int scoreToAdd);

private:
    int playerScore;
    std::shared_ptr<TextViewController> textViewController;
};


#endif //PAS_CMAN_SCORECONTROLLER_H
