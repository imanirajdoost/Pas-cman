
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
    if (collisionController->hasCollision(player->getRect(), fruitController->fruit.getRect()))
        fruitController->fruit.getEaten();
//        eat(fruitController->fruit);
}

PlayerController::PlayerController(shared_ptr<CollisionController> colController, shared_ptr<Player> p,
                                   shared_ptr<DotController> dController, shared_ptr<FruitController> fController) {
    collisionController = std::move(colController);
    dotController = std::move(dController);
    fruitController = std::move(fController);
    player = std::move(p);
}

void PlayerController::setMoveIntent(MoveDirection direction) {
    player->setMoveIntent(direction);
}
