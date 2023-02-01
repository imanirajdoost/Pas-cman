#include "Player.h"
#include "DotBig.h"
#include <typeinfo>

// get pacman's sprite from the sprite sheet
SDL_Rect player_r = { 21, 9, 16, 16 }; 
SDL_Rect player_l = { 37,161, 16,16 }; 
SDL_Rect player_d = { 105,161, 16,16 }; 
SDL_Rect player_u = { 71,161, 16,16 };

Player::Player(int x, int y, const int initHealth) {
    _health = initHealth;
    // @todo : Update health UI

    rect.x = x;
    rect.y = y;
    rect.w = 32;
    rect.h = 32;

    _r_sprite = player_r;
    _l_sprite = player_l;
    _d_sprite = player_d;
    _u_sprite = player_u;
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