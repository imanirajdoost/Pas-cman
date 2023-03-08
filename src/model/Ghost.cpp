#include <iostream>
#include "model/Ghost.h"
#include "GameVars.h"


Ghost::Ghost(){
//    rect.x = x;
//    rect.y = y;
//
//    _next_pos.x = x;
//    _next_pos.y = y;

    rect.w = TILESIZE;
    rect.h = TILESIZE;
}


Blinky::Blinky() {
    // Set default animation and sprite and add animations
    addAnimation({"default", {Blinky::blinky_r1, Blinky::blinky_r2}});
    addAnimation({"move_up", {Blinky::blinky_u1, Blinky::blinky_u2}});
    addAnimation({"move_down", {Blinky::blinky_d1, Blinky::blinky_d2}});
    addAnimation({"move_left", {Blinky::blinky_l1, Blinky::blinky_l2}});
    addAnimation({"move_right", {Blinky::blinky_r1, Blinky::blinky_r2}});

    setAnimation("default");
}


//void Blinky::setNextPos(const std::vector<std::vector<MTYPE>>& map, const MoveDirection& direction) {
//    if (GameController::animationCounter%4 == 0) {
//        _next_pos.x += speed;
//    }
//
//    setMoveDirection(direction);
//}

Pinky::Pinky() {
    // Set default animation and sprite and add animations
    addAnimation({"default", {Pinky::pinky_r1, Pinky::pinky_r2}});
    addAnimation({"move_up", {Pinky::pinky_u1, Pinky::pinky_u2}});
    addAnimation({"move_down", {Pinky::pinky_d1, Pinky::pinky_d2}});
    addAnimation({"move_left", {Pinky::pinky_l1, Pinky::pinky_l2}});
    addAnimation({"move_right", {Pinky::pinky_r1, Pinky::pinky_r2}});

    setAnimation("default");
}

Inky::Inky() : Ghost()  {
    // Set default animation and sprite and add animations
    addAnimation({"default", {Inky::inky_r1, Inky::inky_r2}});
    addAnimation({"move_up", {Inky::inky_u1, Inky::inky_u2}});
    addAnimation({"move_down", {Inky::inky_d1, Inky::inky_d2}});
    addAnimation({"move_left", {Inky::inky_l1, Inky::inky_l2}});
    addAnimation({"move_right", {Inky::inky_r1, Inky::inky_r2}});

    setAnimation("default");
}

Clyde::Clyde() {
    // Set default animation and sprite and add animations
    addAnimation({"default", {Clyde::clyde_r1, Clyde::clyde_r2}});
    addAnimation({"move_up", {Clyde::clyde_u1, Clyde::clyde_u2}});
    addAnimation({"move_down", {Clyde::clyde_d1, Clyde::clyde_d2}});
    addAnimation({"move_left", {Clyde::clyde_l1, Clyde::clyde_l2}});
    addAnimation({"move_right", {Clyde::clyde_r1, Clyde::clyde_r2}});

    setAnimation("default");
}

