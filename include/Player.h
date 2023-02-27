#ifndef PLAYER_H
#define PLAYER_H

#include "MovableGameObject.h"
#include "Dot.h"

/**
 * Main pac-man player object
*/
class Player : public MovableGameObject {

private:
    int _health;
public:
    int getHealth() const;
    void setHealth(int health);

private:
    // Player's health
    MoveDirection moveIntent = MoveDirection::NONE;
    static int PLAYER_MOVE_THRESHOLD;

    // get pacman's sprite from the sprite sheet
    static SDL_Rect player_fill;
    static SDL_Rect player_r1;
    static SDL_Rect player_r2;
    static SDL_Rect player_l1;
    static SDL_Rect player_l2;
    static SDL_Rect player_d1;
    static SDL_Rect player_d2;
    static SDL_Rect player_u1;
    static SDL_Rect player_u2;

public:
    Player(SDL_Rect defaultSprite, int x, int y, int initHealth);   // Constructor that initilalizes player with the given health

    void eat(Dot& dotToEat) const;         // Action to eat a Dot
    void die();                                  // Die when hit by a ghost
    void gameOver();                             // Game over when no more health is remaining
    void setNextPos(const std::vector<std::vector<MTYPE>>& map, const MoveDirection& direction) override;
    void controlMove();
    SDL_Rect getNextStepRect(MoveDirection dir);

    void move() override;
    
    void setRawNextPos(SDL_Rect nextPos);

    MoveDirection getMoveIntent() const;
    void setMoveIntent(const MoveDirection& direction);

};

#endif