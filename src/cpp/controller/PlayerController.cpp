#include "../../header/controller/PlayerController.h"

void PlayerController::tick(Player& player) {
//    MoveDirection nextPlayerMove = player.getMoveIntent();
    // Control movement of the player based on the given input
    player.controlMove();
}

PlayerController::PlayerController() {

}

void PlayerController::setMoveIntent(Player& player, MoveDirection direction) {
    player.setMoveIntent(direction);
}
