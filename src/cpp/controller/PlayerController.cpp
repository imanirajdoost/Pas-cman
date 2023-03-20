
#include <utility>

#include "header/controller/PlayerController.h"

void PlayerController::tick() {
//    MoveDirection nextPlayerMove = player.getMoveIntent();
    // Control movement of the player based on the given input
    player->controlMove(*collisionController);

    // Check for collision with coins
    for (auto i = dotController->dots.begin(); i < dotController->dots.end(); ++i) {
        if (collisionController->hasCollision(player->getRect(), i->get()->getRect())) {
            i->get()->getEaten();
//            player->eat(*i->get());
            break;
        }
    }

    // Check for collision with bonus objs
    if (collisionController.hasCollision(player->getRect(), GameController::fruit.getRect()))
        eat(GameController::fruit);
}

PlayerController::PlayerController(shared_ptr<CollisionController> colController, shared_ptr<Player> p, shared_ptr<DotController> dController) {
    collisionController = std::move(colController);
    dotController = std::move(dController);
    player = std::move(p);
}

void PlayerController::setMoveIntent(MoveDirection direction) {
    player->setMoveIntent(direction);
}
