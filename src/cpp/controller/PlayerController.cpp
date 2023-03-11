#include "../../header/controller/PlayerController.h"

void PlayerController::tick() {
    MoveDirection nextPlayerMove = player.getMoveIntent();
    // Control movement of the player based on the given input
    player.controlMove();
}

PlayerController::PlayerController() {

}

void PlayerController::setMoveIntent(MoveDirection direction) {
    player.setMoveIntent(direction);
}
