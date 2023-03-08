#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <tuple>

#include "Ghost.h"
#include "GameVars.h"
#include "GameController.h"
#include "CollisionManager.h"
#include "Map.h"

SDL_Rect Blinky::blinky_r1 = { 4,124, 14,14 };
SDL_Rect Blinky::blinky_r2 = { 21,124, 14,14 };
SDL_Rect Blinky::blinky_l1 = { 38,124, 14,14 };
SDL_Rect Blinky::blinky_l2 = { 55,124, 14,14 };
SDL_Rect Blinky::blinky_d1 = { 106,124, 14,14 };
SDL_Rect Blinky::blinky_d2 = { 123,124, 14,14 };
SDL_Rect Blinky::blinky_u1 = { 72,124, 14,14 };
SDL_Rect Blinky::blinky_u2 = { 89,124, 14,14 };

SDL_Rect Pinky::pinky_r1 = { 4,142, 14,14 };
SDL_Rect Pinky::pinky_r2 = { 21,142, 14,14 };
SDL_Rect Pinky::pinky_l1 = { 38,142, 14,14 };
SDL_Rect Pinky::pinky_l2 = { 55,142, 14,14 };
SDL_Rect Pinky::pinky_d1 = { 106,142, 14,14 };
SDL_Rect Pinky::pinky_d2 = { 123,142, 14,14 };
SDL_Rect Pinky::pinky_u1 = { 72,142, 14,14 };
SDL_Rect Pinky::pinky_u2 = { 89,142, 14,14 };

SDL_Rect Inky::inky_r1 = { 4,160, 14,14 };
SDL_Rect Inky::inky_r2 = { 21,160, 14,14 };
SDL_Rect Inky::inky_l1 = { 38,160, 14,14 };
SDL_Rect Inky::inky_l2 = { 55,160, 14,14 };
SDL_Rect Inky::inky_d1 = { 106,160, 14,14 };
SDL_Rect Inky::inky_d2 = { 123,160, 14,14 };
SDL_Rect Inky::inky_u1 = { 72,160, 14,14 };
SDL_Rect Inky::inky_u2 = { 89,160, 14,14 };

SDL_Rect Clyde::clyde_r1 = { 4,178, 14,14 };
SDL_Rect Clyde::clyde_r2 = { 21,178, 14,14 };
SDL_Rect Clyde::clyde_l1 = { 38,178, 14,14 };
SDL_Rect Clyde::clyde_l2 = { 55,178, 14,14 };
SDL_Rect Clyde::clyde_d1 = { 106,178, 14,14 };
SDL_Rect Clyde::clyde_d2 = { 123,178, 14,14 };
SDL_Rect Clyde:: clyde_u1 = { 72,178, 14,14 };
SDL_Rect Clyde:: clyde_u2 = { 89,178, 14,14 };

Ghost::Ghost(SDL_Rect defaultSprite, int x, int y) : MovableGameObject(defaultSprite) {
    rect.x = x;
    rect.y = y;

    _next_pos.x = x;
    _next_pos.y = y;

    rect.w = TILESIZE;
    rect.h = TILESIZE;
}


Blinky::Blinky(SDL_Rect defaultSprite, int x, int y): Ghost(defaultSprite, x, y)  {
    // Set default animation and sprite and add animations
    addAnimation({"default", {Blinky::blinky_r1, Blinky::blinky_r2}});
    addAnimation({"move_up", {Blinky::blinky_u1, Blinky::blinky_u2}});
    addAnimation({"move_down", {Blinky::blinky_d1, Blinky::blinky_d2}});
    addAnimation({"move_left", {Blinky::blinky_l1, Blinky::blinky_l2}});
    addAnimation({"move_right", {Blinky::blinky_r1, Blinky::blinky_r2}});

    setAnimation("default");
}

void Blinky::setMoveIntent(Player &player) {

    int bx = getX();
    int by = getY();

    if (
        std::find(
            Map::intersections.begin(), 
            Map::intersections.end(), 
            make_tuple<int, int>(bx/TILESIZE, by/TILESIZE)
        ) != Map::intersections.end()
    ) {
        int px = player.getX();
        int py = player.getY();

        int dx = abs(bx - px);
        int dy = abs(by - py);

        if (dx > dy) {
            if (bx - px > 0) {
                moveIntent = MoveDirection::LEFT;
            }  else {
                moveIntent = MoveDirection::RIGHT;
            }
        } else {
            if (by - py > 0) {
                moveIntent = MoveDirection::DOWN;
            }  else {
                moveIntent = MoveDirection::UP;
            }
        }

        Collider nextCol = CollisionManager::getRectAtDirection(rect, direction);
        Collider intentionCol = CollisionManager::getRectAtDirection(rect, moveIntent);
        SDL_Rect nextStep = getNextStepRect(moveIntent);

        //if (nextCol.getType() == MTYPE::WALL && CollisionManager::hasCollision(nextStep, nextCol.getRect())) {
            //moveIntent = MoveDirection::DOWN;
        //}

    } else {
        // dont change move intent
    }

}

Pinky::Pinky(SDL_Rect defaultSprite, int x, int y) : Ghost(defaultSprite, x, y) {
    // Set default animation and sprite and add animations
    addAnimation({"default", {Pinky::pinky_r1, Pinky::pinky_r2}});
    addAnimation({"move_up", {Pinky::pinky_u1, Pinky::pinky_u2}});
    addAnimation({"move_down", {Pinky::pinky_d1, Pinky::pinky_d2}});
    addAnimation({"move_left", {Pinky::pinky_l1, Pinky::pinky_l2}});
    addAnimation({"move_right", {Pinky::pinky_r1, Pinky::pinky_r2}});

    setAnimation("default");
}

void Pinky::setMoveIntent(Player &player) {
    moveIntent = MoveDirection::RIGHT;
}


Inky::Inky(SDL_Rect defaultSprite, int x, int y) : Ghost(defaultSprite, x, y)  {
    // Set default animation and sprite and add animations
    addAnimation({"default", {Inky::inky_r1, Inky::inky_r2}});
    addAnimation({"move_up", {Inky::inky_u1, Inky::inky_u2}});
    addAnimation({"move_down", {Inky::inky_d1, Inky::inky_d2}});
    addAnimation({"move_left", {Inky::inky_l1, Inky::inky_l2}});
    addAnimation({"move_right", {Inky::inky_r1, Inky::inky_r2}});

    setAnimation("default");
}

void Inky::setMoveIntent(Player &player, Blinky &blinky) {
    moveIntent = MoveDirection::RIGHT;
}


Clyde::Clyde(SDL_Rect defaultSprite, int x, int y) : Ghost(defaultSprite, x, y)  {
    // Set default animation and sprite and add animations
    addAnimation({"default", {Clyde::clyde_r1, Clyde::clyde_r2}});
    addAnimation({"move_up", {Clyde::clyde_u1, Clyde::clyde_u2}});
    addAnimation({"move_down", {Clyde::clyde_d1, Clyde::clyde_d2}});
    addAnimation({"move_left", {Clyde::clyde_l1, Clyde::clyde_l2}});
    addAnimation({"move_right", {Clyde::clyde_r1, Clyde::clyde_r2}});

    setAnimation("default");
}

void Clyde::setMoveIntent(Player &player) {
    moveIntent = MoveDirection::RIGHT;
}
