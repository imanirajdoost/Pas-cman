#ifndef PAS_CMAN_PLAYERCONTROLLER_H
#define PAS_CMAN_PLAYERCONTROLLER_H

#include "header/model/Player.h"
#include "DotController.h"
#include "FruitController.h"
#include "ScoreController.h"
#include "header/view/SDLViewController.h"
#include "GhostController.h"
#include "PauseController.h"

/**
 * PlayerController class manages the Pac-Man player's movements, actions and interactions with other game objects.
 */
class PlayerController {
public:
    /**
     * Constructor for PlayerController.
     * @param colController A shared pointer to the CollisionController object.
     * @param p A shared pointer to the Player object.
     * @param dController A shared pointer to the DotController object.
     * @param fController A shared pointer to the FruitController object.
     * @param sController A shared pointer to the ScoreController object.
     * @param tController A shared pointer to the TextViewController object.
     * @param gController A shared pointer to the GhostController object.
     * @param pController A shared pointer to the PauseController object.
     */
    PlayerController(shared_ptr<CollisionController> colController, shared_ptr<Player> p,
                     shared_ptr<DotController> dController, shared_ptr<FruitController> fController, shared_ptr<ScoreController> sController,
                     shared_ptr<TextViewController> tController, shared_ptr<GhostController> gController, shared_ptr<PauseController> pController);

    /**
     * Sets the move intent for the Pac-Man player.
     * @param direction The intended movement direction of the player.
     */
    void setMoveIntent(MoveDirection direction);

    /**
     * Tick function for the PlayerController. Called on every frame.
     */
    void tick();

private:
    shared_ptr<CollisionController> collisionController; /**< A shared pointer to the CollisionController object. */
    shared_ptr<DotController> dotController; /**< A shared pointer to the DotController object. */
    shared_ptr<FruitController> fruitController; /**< A shared pointer to the FruitController object. */
    shared_ptr<ScoreController> scoreController; /**< A shared pointer to the ScoreController object. */
    shared_ptr<TextViewController> textViewController; /**< A shared pointer to the TextViewController object. */
    shared_ptr<GhostController> ghostController; /**< A shared pointer to the GhostController object. */
    shared_ptr<PauseController> pauseController; /**< A shared pointer to the PauseController object. */
    shared_ptr<Player> player; /**< A shared pointer to the Player object. */
};

#endif //PAS_CMAN_PLAYERCONTROLLER_H
