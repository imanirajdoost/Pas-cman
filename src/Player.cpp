#include "Player.h"
#include "DotBig.h"
#include <typeinfo>
#include "GameVars.h"

// get pacman's sprite from the sprite sheet
SDL_Rect player_r = { 20, 89, 16, 16 }; 
SDL_Rect player_l = { 46,89, 16,16 }; 
SDL_Rect player_d = { 109,89, 16,16 }; 
SDL_Rect player_u = { 75,89, 16,16 };

Player::Player(int x, int y, const int initHealth) : _health{initHealth} {
    // _health = initHealth;
    // @todo : Update health UI

    rect.x = x;
    rect.y = y;
    rect.w = 14;
    rect.h = 14;

    _r_sprite = player_r;
    _l_sprite = player_l;
    _d_sprite = player_d;
    _u_sprite = player_u;
}

void Player::setNextPos(const std::vector<std::vector<MTYPE>>& map, const MoveDirection& direction) {

    switch (direction)
    {
        case MoveDirection::LEFT:
            _next_pos.x -= speed;
            break;
        case MoveDirection::RIGHT:
            _next_pos.x += speed;
            break;
        case MoveDirection::UP:
            _next_pos.y -= speed;
            break;
        case MoveDirection::DOWN:
            _next_pos.y += speed;
            break;
    }

}

void Player::eat(const Dot& dotToEat) const {
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