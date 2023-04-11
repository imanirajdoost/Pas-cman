#ifndef PLAYER_H
#define PLAYER_H

#include "MovableGameObject.h"
#include "header/model/component/HealthComponent.h"
#include "Map.h"
#include "header/controller/CollisionController.h"

/**
 * @brief Main pac-man player object.
 */
class Player : public MovableGameObject, public HealthComponent {

private:
    MoveDirection moveIntent = MoveDirection::NONE;

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

    /** @brief Number of pixels to let player change direction if they are not in the middle */
    const int PLAYER_MOVE_THRESHOLD = 6;

public:
    /**
     * @brief Constructor.
     * @param initHealth Initial health of the player.
     */
    explicit Player(short initHealth);

    /**
     * @brief Set the next position of the player.
     * @param map The game map.
     * @param direction The intended direction to move.
     */
    void setNextPos(const std::vector<std::vector<MTYPE>> &map, const MoveDirection &direction) override;

    /**
     * @brief Control the player's movement.
     * @param collisionController The collision controller for checking collisions with walls.
     */
    void controlMove(CollisionController &collisionController);

    /**
     * @brief Get the next step's rectangle based on the intended direction.
     * @param dir The intended direction to move.
     * @return SDL_Rect The next step's rectangle.
     */
    SDL_Rect getNextStepRect(MoveDirection dir);

    /**
     * @brief Move the player.
     */
    void move() override;

    /**
     * @brief Trigger the player's death.
     */
    void die() override;

    /**
     * @brief Get the player's intended movement direction.
     * @return MoveDirection The intended movement direction.
     */
    MoveDirection getMoveIntent() const;

    /**
     * @brief Set the player's intended movement direction.
     * @param direction The intended movement direction.
     */
    void setMoveIntent(const MoveDirection &direction);
};

#endif
