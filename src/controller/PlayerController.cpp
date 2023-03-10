//
// Created by iman on 10/03/23.
//


#include "controller/PlayerController.h"

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
