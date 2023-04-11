/**
@file ScoreController.h
@brief A class responsible for managing the player's score and updating the text view.
*/

#ifndef PAS_CMAN_SCORECONTROLLER_H
#define PAS_CMAN_SCORECONTROLLER_H


#include <memory>
#include "header/view/TextViewController.h"

class ScoreController {
public:
    /**
* @brief Constructs a new ScoreController object.
* @param tController A shared pointer to a TextViewController object.
*/
    ScoreController(std::shared_ptr<TextViewController> tController);

    /**
 * @brief Adds a given amount to the player's score.
 * @param scoreToAdd The amount of score to add.
 */
    void addScore(int scoreToAdd);

private:
    int playerScore; /**< The current score of the player. */
    std::shared_ptr<TextViewController> textViewController; /**< A shared pointer to a TextViewController object. */
};


#endif //PAS_CMAN_SCORECONTROLLER_H
