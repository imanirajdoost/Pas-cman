#include "Player.h"
#include "DotBig.h"
#include <typeinfo>

// get pacman's sprite from the sprite sheet
SDL_Rect player_r = { 20, 89, 16, 16 }; 
SDL_Rect player_l = { 46,89, 16,16 }; 
SDL_Rect player_d = { 109,89, 16,16 }; 
SDL_Rect player_u = { 75,89, 16,16 };

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

void Player::setNextPos(const Map& map, const MoveDirection& direction) {

    switch (direction)
    {
        case LEFT:
            _next_pos.x--;
            break;
        case RIGHT:
            _next_pos.x++;
            break;
        case UP:
            _next_pos.y++;
            break;
        case DOWN:
            _next_pos.y--;
            break;
    }

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