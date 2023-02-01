#include "Player.h"
#include "DotBig.h"
#include <typeinfo>

// get pacman's sprite from the sprite sheet
SDL_Rect player_sp = {9,4, 16,16};

Player::Player(const int initHealth) {
    _health = initHealth;
    // @todo : Update health UI
}

void Player::eat(Dot dotToEat) {
    dotToEat.getEaten();
    // @todo increase score
    // if((typeid(dotToEat) == typeid(DotBig)) {
    //     std::cout << " Dot big has been eaten" << std::endl;
    // }
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