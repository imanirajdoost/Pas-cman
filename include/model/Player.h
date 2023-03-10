#ifndef PLAYER_H
#define PLAYER_H

#include "MovableGameObject.h"
#include "model/component/HealthComponent.h"

/**
 * Main pac-man player object
*/
class Player : public MovableGameObject, public HealthComponent {

private:
    MoveDirection moveIntent = MoveDirection::NONE;

    // get pacman's sprite from the sprite sheet
    const SDL_Rect player_fill = {4, 90, 14, 14};
    const SDL_Rect player_r1 = {21, 90, 13, 14};
    const SDL_Rect player_r2 = {36, 90, 9, 14};
    const SDL_Rect player_l1 = {48, 90, 13, 14};
    const SDL_Rect player_l2 = {64, 90, 9, 14};
    const SDL_Rect player_d1 = {110, 91, 14, 13};
    const SDL_Rect player_d2 = {127, 95, 14, 9};
    const SDL_Rect player_u1 = {76, 91, 14, 13};
    const SDL_Rect player_u2 = {93, 90, 14, 14};

    const SDL_Rect player_die1 = {4, 111, 16, 8};
    const SDL_Rect player_die2 = {23, 111, 16, 8};
    const SDL_Rect player_die3 = {42, 111, 16, 8};
    const SDL_Rect player_die4 = {61, 111, 16, 8};
    const SDL_Rect player_die5 = {80, 111, 16, 8};
    const SDL_Rect player_die6 = {99, 111, 14, 8};
    const SDL_Rect player_die7 = {116, 111, 10, 8};
    const SDL_Rect player_die8 = {129, 111, 6, 8};
    const SDL_Rect player_die9 = {137, 111, 4, 8};

    const int PLAYER_MOVE_THRESHOLD = 6;

public:
    explicit Player(short initHealth);   // Constructor

//    void eat(EatableComponent &dotToEat) const;         // Action to eat a EatableComponent
    void setNextPos(const std::vector<std::vector<MTYPE>> &map, const MoveDirection &direction) override;

    void controlMove();

    SDL_Rect getNextStepRect(MoveDirection dir);

    void move() override;

    MoveDirection getMoveIntent() const;

    void setMoveIntent(const MoveDirection &direction);

};

#endif