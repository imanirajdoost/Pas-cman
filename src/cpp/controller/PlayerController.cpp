
#include <utility>

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
        if (fruitController->deleteFruit())
            scoreController->addScore(FRUIT_SCORE);
}

PlayerController::PlayerController(shared_ptr<CollisionController> colController, shared_ptr<Player> p,
                                   shared_ptr<DotController> dController, shared_ptr<FruitController> fController,
                                   shared_ptr<ScoreController> sController, shared_ptr<TextViewController> tController) {
    collisionController = std::move(colController);
    dotController = std::move(dController);
    fruitController = std::move(fController);
    scoreController = std::move(sController);
    textViewController = std::move(tController);
    player = std::move(p);

    textViewController->setHealthUI(player->getHealth());
}

void PlayerController::setMoveIntent(MoveDirection direction) {
    player->setMoveIntent(direction);
}
