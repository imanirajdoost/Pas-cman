#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "Dot.h"

/**
 * Main pac-man player object
*/
class Player : GameObject {

private:
    int _health;                    // Player's health

public:
    Player(const int initHealth);   // Constructor that initilalizes player with the given health

    void eat(Dot dotToEat);         // Action to eat a Dot
    void die();                     // Die when hit by a ghost
    void gameOver();                // Game over when no more health is remaining

    void move(moveDirection dir);   // moves the player based on the given direction
};

#endif