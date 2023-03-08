#include "Player.h"
#include "DotBig.h"
#include <iostream>
#include <cmath>
#include "GameController.h"
#include "CollisionManager.h"

// get pacman's sprite from the sprite sheet
SDL_Rect Player::player_fill = {4, 90, 14, 14};
SDL_Rect Player::player_r1 = {21, 90, 14, 14};
SDL_Rect Player::player_r2 = {34, 90, 14, 14};
SDL_Rect Player::player_l1 = {47, 90, 14, 14};
SDL_Rect Player::player_l2 = {61, 90, 14, 14};
SDL_Rect Player::player_d1 = {110, 90, 14, 14};
SDL_Rect Player::player_d2 = {127, 90, 14, 14};
SDL_Rect Player::player_u1 = {76, 90, 14, 14};
SDL_Rect Player::player_u2 = {93, 90, 14, 14};

SDL_Rect Player::player_die1 = {4, 111, 16, 8};
SDL_Rect Player::player_die2 = {23, 111, 16, 8};
SDL_Rect Player::player_die3 = {42, 111, 16, 8};
SDL_Rect Player::player_die4 = {61, 111, 16, 8};
SDL_Rect Player::player_die5 = {80, 111, 16, 8};
SDL_Rect Player::player_die6 = {99, 111, 14, 8};
SDL_Rect Player::player_die7 = {116, 111, 10, 8};
SDL_Rect Player::player_die8 = {129, 111, 6, 8};
SDL_Rect Player::player_die9 = {137, 111, 4, 8};

int Player::PLAYER_MOVE_THRESHOLD = 6;

Player::Player(SDL_Rect defaultSprite, int x, int y, int initHealth) : MovableGameObject(defaultSprite),
                                                                       _health{initHealth} {
    // _health = initHealth;
    // @todo : Update health UI

    rect.x = x;
    rect.y = y;

    // Set the size of the player rect
    rect.w = 32;
    rect.h = 32;

    int PLAYER_MOVE_THRESHOLD = 6;

    // Set default animation and sprite and add animations
    addAnimation({"default", {Player::player_fill, Player::player_r1, Player::player_r2}});
    addAnimation({"move_up", {Player::player_fill, Player::player_u1, Player::player_u2}});
    addAnimation({"move_down", {Player::player_fill, Player::player_d1, Player::player_d2}});
    addAnimation({"move_left", {Player::player_fill, Player::player_l1, Player::player_l2}});
    addAnimation({"move_right", {Player::player_fill, Player::player_r1, Player::player_r2}});
    addAnimation({"die", {Player::player_die1, Player::player_die2, Player::player_die3, Player::player_die4,
                          Player::player_die5, Player::player_die6, Player::player_die7, Player::player_die8,
                          Player::player_die9}});

    setAnimation("default");
}

void Player::eat(Eatable &dotToEat) const {
    dotToEat.getEaten(dotToEat);
}

void Player::die() {
    // @todo implement dying
    _health--;

    if (_health <= 0) {
        gameOver();
    }
}

void Player::gameOver() {
    // @todo show game over UI or reset the game
}

void Player::setRawNextPos(const SDL_Rect nextPos) {
    _next_pos = nextPos;
}

void Player::move() {
    MovableGameObject::move();

    // Check for collision with coins
    for (auto i = GameController::dots.begin(); i < GameController::dots.end(); ++i) {
        if (CollisionManager::hasCollision(getRect(), i->get()->getRect())) {
            eat(*i->get());
            break;
        }
    }

    // Check for collision with bonus objs
    if(CollisionManager::hasCollision(getRect(), GameController::fruit.getRect()))
        eat(GameController::fruit);
}

int Player::getHealth() const {
    return _health;
}

void Player::setHealth(int health) {
    _health = health;
}
