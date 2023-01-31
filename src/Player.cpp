#include "Player.h"

Player::Player(const int initHealth) {
    _health = initHealth;
    // @todo : Update health UI
}

void Player::eat(Dot dotToEat) {
    dotToEat.getEaten();
    // @todo increase score
}

void Player::die() {
    // @todo implement dying
    _health--;

    if(_health <= 0) {
        gameOver();
    }
}

void Player::gameOver() {
    // @todo show game over UI or reset the game
}

void Player::move(moveDirection dir) {
    
}

