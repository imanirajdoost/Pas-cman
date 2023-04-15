
#include <utility>
#include <iostream>

#include "header/controller/PlayerController.h"
#include "header/GameVars.h"

void PlayerController::tick() {
//    MoveDirection nextPlayerMove = player.getMoveIntent();
    // Control movement of the player based on the given input
    player->controlMove(*collisionController);

    // Check for collision with coins
    for (auto i = dotController->dots.begin(); i < dotController->dots.end(); ++i) {
        if (collisionController->hasCollision(player->getRect(), i->get()->getRect())) {
            if (i->get()->getIndex() >= 0) {
                // set default score for small dot
                int score = SMALL_DOT_SCORE;

                // Check if it's a big dot
                int x = i->get()->getTileX();
                int y = i->get()->getTileY();
                if (dotController->isBigDot(y, x))
                    score = BIG_DOT_SCORE;

                if (dotController->deleteDot(*i->get()))
                    scoreController->addScore(score);
                break;
            }
        }
    }

    // Check for collision with bonus objs
    if (collisionController->hasCollision(player->getRect(), fruitController->fruit.getRect()))
        if (fruitController->deleteFruit()) {
//            pauseController->pauseFor(200);
            scoreController->addScore(FRUIT_SCORE);
        }

    // Check for collision with ghosts
    // TODO: This has two phases, if ghosts are in 'flee mode' they must be eaten, otherwise player dies
    auto ghosts = ghostController->getAllGhosts();
    for (auto &ghost: *ghosts) {
        if (collisionController->hasCollision(player->getRect(), ghost->getRect())) {
            // TODO: Check if should eat or die
            std::cout << "hit ghost" << std::endl;
            short remainingHealth = player->die();
            textViewController->setHealthUI(remainingHealth);
            if (remainingHealth > 0) {
                pauseController->pauseFor(default_variables::reset_level_time, resetGame);
            } else {
                pauseController->pause();
                scoreController->updateHighscore();
                textViewController->writeHighScore(scoreController->getHighscore());
                textViewController->writeOnUI("game_over", "gameover", 270, 350);
            }
            break;
        }
    }

    // Handle transition between left and right doors
    int teleportDoor = collisionController->getCollisionWithTeleportDoor(player->getRect());
    if (teleportDoor >= 0) {
        switch (teleportDoor) {
            case 0:
                if (player->getMoveDirection() == MoveDirection::LEFT) {
                    // move from left to right
                    player->setPos(20 * TILESIZE, 13 * TILESIZE);
                    player->resetNextPos();
                }
                break;
            case 1:
                if (player->getMoveDirection() == MoveDirection::RIGHT) {
                    // move from right to left
                    player->setPos(0 * TILESIZE, 13 * TILESIZE);
                    player->resetNextPos();
                }
                break;
        }
    }
}

PlayerController::PlayerController(shared_ptr<CollisionController> colController, shared_ptr<Player> p,
                                   shared_ptr<DotController> dController, shared_ptr<FruitController> fController,
                                   shared_ptr<ScoreController> sController, shared_ptr<TextViewController> tController,
                                   shared_ptr<GhostController> gController, shared_ptr<PauseController> pController,
                                   std::function<void()> _resetFunction) {
    collisionController = std::move(colController);
    dotController = std::move(dController);
    fruitController = std::move(fController);
    scoreController = std::move(sController);
    textViewController = std::move(tController);
    ghostController = std::move(gController);
    pauseController = std::move(pController);
    player = std::move(p);

    resetGame = std::move(_resetFunction);

    textViewController->setHealthUI(player->getHealth());
}

void PlayerController::setMoveIntent(MoveDirection direction) {
    player->setMoveIntent(direction);
}
