#ifndef MOVABLEGAMEOBJECT_H
#define MOVABLEGAMEOBJECT_H

#include "GameObject.h"
#include "Map.h"

enum class MoveDirection {
    NONE = 0,
    UP = 1,
    DOWN = 2,
    LEFT = 3,
    RIGHT = 4
};

/**
 * @brief A class representing a game object that can move.
 *
 * This class inherits from GameObject and adds features to represent
 * the next position of the object, its speed and direction of movement.
 */
class MovableGameObject : public GameObject {

protected:
    SDL_Rect _next_pos; ///< The next position of the object.
    int speed = 4; ///< The speed at which the object moves.
    MoveDirection direction = MoveDirection::NONE; ///< The current direction of movement of the object.
    MoveDirection lastDirection = MoveDirection::NONE; ///< The last direction of movement of the object.
    bool isMoveEnabled; ///< Whether movement is enabled for the object or not.

public:
    /**
     * @brief Constructor with default parameters.
     *
     * @param defaultSp The default sprite of the object.
     * @param initPos The initial position of the object.
     */
    explicit MovableGameObject(SDL_Rect defaultSp, SDL_Rect initPos);

    /**
     * @brief Constructor with specified parameters.
     *
     * @param animName The name of the animation of the object.
     * @param sprites A vector of SDL_Rect representing the frames of the animation.
     * @param _isAnimated A boolean value indicating whether the object is animated or not.
     * @param initPos The initial position of the object.
     */
    MovableGameObject(const string &animName, const vector<SDL_Rect> &sprites, bool _isAnimated, SDL_Rect initPos);

    /**
     * @brief Constructor with specified parameters.
     * @param initPos The initial position of the object.
     */
    explicit MovableGameObject(SDL_Rect initPos);

    /**
     * @brief Get the speed of the object.
     *
     * @return The speed of the object.
     */
    int getSpeed() const;

    /**
     * @brief Get the current direction of movement of the object.
     *
     * @return The current direction of movement of the object.
     */
    MoveDirection getMoveDirection() const;

    /**
     * @brief Set the current direction of movement of the object.
     *
     * @param newDirection The new direction of movement to set.
     */
    void setMoveDirection(const MoveDirection &newDirection);

    /**
     * @brief Set the sprite of the object based on its current direction.
     *
     * @param newDirection The new direction of movement to set the sprite for.
     */
    virtual void setDirectionSprite(const MoveDirection &newDirection);

    /**
     * @brief Reset the current direction of movement of the object to NONE.
     */
    void resetMoveDirection();

    /**
     * @brief Get the next position of the object.
     *
     * @return The next position of the object.
     */
    SDL_Rect getNextPos() const;

    /**
     * @brief Set the next position of the object based on the current direction of movement.
     *
     * @param map The tilemap of the game.
     * @param direction The current direction of movement of the object.
     */
    virtual void setNextPos(const std::vector<std::vector<MTYPE>> &map, const MoveDirection &direction) = 0;

    /**
     * @brief Reset the next position of the object to its current position.
     */
    void resetNextPos();

    /**
     * @brief Move the object to its next position.
     */
    virtual void move();

    void reset_state() override;
};

#endif
