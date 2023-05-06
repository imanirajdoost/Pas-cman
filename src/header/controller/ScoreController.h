/**
@file ScoreController.h
@brief A class responsible for managing the player's score and updating the text view.
*/

#ifndef PAS_CMAN_SCORECONTROLLER_H
#define PAS_CMAN_SCORECONTROLLER_H


#include <memory>
#include "header/view/TextViewController.h"
#include "DataController.h"

using namespace std;

class ScoreController {
public:
    /**
* @brief Constructs a new ScoreController object.
* @param tController A shared pointer to a TextViewController object.
*/
    ScoreController(shared_ptr<TextViewController> tController, shared_ptr<DataController> dController);

    /**
 * @brief Adds a given amount to the player's score.
 * @param scoreToAdd The amount of score to add.
 */
    void addScore(int scoreToAdd);

    /**
     * @brief Updates the highscore if the player's score is higher than the current highscore.
     */
    void updateHighscore();

    /**
     * @brief Returns the highscore.
     * @return The highscore.
     */
    int getHighscore();

private:
    int playerScore; /**< The current score of the player. */
    shared_ptr<TextViewController> textViewController; /**< A shared pointer to a TextViewController object. */
    shared_ptr<DataController> dataController; /**< A shared pointer to a DataController object. */
};


#endif //PAS_CMAN_SCORECONTROLLER_H
