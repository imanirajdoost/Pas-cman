#ifndef PAS_CMAN_FRUITCONTROLLER_H
#define PAS_CMAN_FRUITCONTROLLER_H


#include "header/model/eatable/Fruit.h"
#include "TimeController.h"
#include "header/view/TextViewController.h"

/**
 * @brief The FruitController class manages the spawn and deletion of the bonus fruit object.
 */
class FruitController {
public:

    /**
    * @brief Constructs a new FruitController object.
    * @param tController A shared pointer to the TimeController object.
     * @param tvController A shared pointer to the TextViewController object.
    */
    explicit FruitController(shared_ptr<TimeController> tController, shared_ptr<TextViewController> tvController);

    Fruit fruit; /**< The bonus fruit object. */

    /**
     * @brief Deletes the bonus fruit object.
     * @return A boolean value indicating if the deletion was successful.
     */
    bool deleteFruit();

    /**
    * @brief The function called by the game loop that handles the logic of the bonus fruit spawn time.
    */
    void tick();

private:

    /**
    * @brief Spawns a new bonus fruit object.
    */
    void spawnFruit();

    /**
     * @brief Resets the bonus fruit position.
     */
    void resetFruitPosition();

    shared_ptr<TimeController> timeController; /**< A shared pointer to the TimeController object. */
    shared_ptr<TextViewController> textViewController; /**< A shared pointer to the TextViewController object. */

    bool fruitAvailable; /**< A boolean value indicating if a bonus fruit is available. */

    ulong last_time_fruit_spawned; /**< The last time a bonus fruit was spawned. */
};


#endif //PAS_CMAN_FRUITCONTROLLER_H
