#ifndef PLAYER_H
#define PLAYER_H

#include "MovableGameObject.h"
#include "Dot.h"

// get pacman's sprite from the sprite sheet
extern SDL_Rect player_r;
extern SDL_Rect player_l;
extern SDL_Rect player_d;
extern SDL_Rect player_u;

/**
 * Main pac-man player object
*/
class Player : public MovableGameObject {

private:
    int _health;                    // Player's health
    MoveDirection moveIntent = MoveDirection::NONE;

public:
    Player(int x, int y, const int initHealth);   // Constructor that initilalizes player with the given health

    void eat(const Dot& dotToEat) const;         // Action to eat a Dot
    void die();                                  // Die when hit by a ghost
    void gameOver();                             // Game over when no more health is remaining
    virtual void setNextPos(const std::vector<std::vector<MTYPE>>& map, const MoveDirection& direction) override;
    
    void setRawNextPos(const SDL_Rect nextPos);

    MoveDirection getMoveIntent() const;
    void setMoveIntent(const MoveDirection& direction);

};

#endif