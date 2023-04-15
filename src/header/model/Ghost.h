/**
 * @file Ghost.h
 * Contains the Ghost class and its subclasses Blinky, Pinky, Inky, and Clyde, which manage the ghosts in the game.
 */

#ifndef GHOST_H
#define GHOST_H

#include "MovableGameObject.h"

/**
 * @brief The Ghost class manages a single ghost in the game.
 */
class Ghost : public MovableGameObject {
protected:
    /**< Whether the ghost is vulnerable or not. */
    bool isVulnerable = false;

public:

    /**
     * @brief Constructs a new Ghost object with the specified default sprite.
     * @param defaultsp The default sprite for the ghost.
     * @param initPos The initial position of the ghost.
     */
    explicit Ghost(SDL_Rect defaultsp, SDL_Rect initPos);

    /**
     * @brief Sets the next position of the ghost based on the current direction and the map.
     *
     * @param map The current game map.
     * @param direction The current direction of the ghost.
     */
    void setNextPos(const std::vector<std::vector<MTYPE>> &map, const MoveDirection &direction) override;

    /**
     * @brief Moves the ghost to its next position.
     */
    void move() override;
};

/**
 * @brief The Blinky class represents the red ghost in the game.
 */
class Blinky : public Ghost {
public:

    /**
     * @brief Constructs a new Blinky object with its predefined sprite rectangles.
     * Inherits from the `Ghost` class and defines the specific sprite
     * rectangles for the ghost.
     */
    Blinky();

private:
    const SDL_Rect blinky_r1 = {4, 124, 14, 14};/**< Right-facing sprite rectangle 1. */
    const SDL_Rect blinky_r2 = {21, 124, 14, 14}; /**< Right-facing sprite rectangle 2. */
    const SDL_Rect blinky_l1 = {38, 124, 14, 14}; /**< Left-facing sprite rectangle 1. */
    const SDL_Rect blinky_l2 = {55, 124, 14, 14};/**< Left-facing sprite rectangle 2. */
    const SDL_Rect blinky_d1 = {106, 124, 14, 14};  /**< Down-facing sprite rectangle 1. */
    const SDL_Rect blinky_d2 = {123, 124, 14, 14};  /**< Down-facing sprite rectangle 2. */
    const SDL_Rect blinky_u1 = {72, 124, 14, 14};/**< Up-facing sprite rectangle 1. */
    const SDL_Rect blinky_u2 = {89, 124, 14, 14};/**< Up-facing sprite rectangle 2. */
};

/**
 * @brief The Pinky class represents the pink ghost in the game.
 */
class Pinky : public Ghost {
public:

    /**
     * @brief Constructs a new Pinky object with its predefined sprite rectangles.
     */
    Pinky();

private:
    const SDL_Rect pinky_r1 = {4, 142, 14, 14};/**< Right-facing sprite rectangle 1. */
    const SDL_Rect pinky_r2 = {21, 142, 14, 14}; /**< Right-facing sprite rectangle 2. */
    const SDL_Rect pinky_l1 = {38, 142, 14, 14}; /**< Left-facing sprite rectangle 1. */
    const SDL_Rect pinky_l2 = {55, 142, 14, 14};/**< Left-facing sprite rectangle 2. */
    const SDL_Rect pinky_d1 = {106, 142, 14, 14};  /**< Down-facing sprite rectangle 1. */
    const SDL_Rect pinky_d2 = {123, 142, 14, 14};  /**< Down-facing sprite rectangle 2. */
    const SDL_Rect pinky_u1 = {72, 142, 14, 14};/**< Up-facing sprite rectangle 1. */
    const SDL_Rect pinky_u2 = {89, 142, 14, 14};/**< Up-facing sprite rectangle 2. */
};

/**
 * @brief The Inky class represents the cyan ghost in the game.
 * Inherits from the `Ghost` class and defines the specific sprite
 * rectangles for the ghost.
 */
class Inky : public Ghost {
public:

    /**
    * @brief Constructs a new Inky object with its predefined sprite rectangles.
    */
    Inky();

private:
    const SDL_Rect inky_r1 = {4, 160, 14, 14};  /**< Right-facing sprite rectangle 1. */
    const SDL_Rect inky_r2 = {21, 160, 14, 14};  /**< Right-facing sprite rectangle 2. */
    const SDL_Rect inky_l1 = {38, 160, 14, 14};  /**< Left-facing sprite rectangle 1. */
    const SDL_Rect inky_l2 = {55, 160, 14, 14}; /**< Left-facing sprite rectangle 2. */
    const SDL_Rect inky_d1 = {106, 160, 14, 14};  /**< Down-facing sprite rectangle 1. */
    const SDL_Rect inky_d2 = {123, 160, 14, 14};  /**< Down-facing sprite rectangle 2. */
    const SDL_Rect inky_u1 = {72, 160, 14, 14}; /**< Up-facing sprite rectangle 1. */
    const SDL_Rect inky_u2 = {89, 160, 14, 14}; /**< Up-facing sprite rectangle 2. */
};

/**
 * @class Clyde
 * @brief A class that represents the Clyde ghost in the game.
 *
 * Inherits from the `Ghost` class and defines the specific sprite
 * rectangles for the Clyde ghost.
 */
class Clyde : public Ghost {
public:

    /**
     * @brief Construct a new Clyde object with default sprite rectangle.
     */
    Clyde();

private:
    const SDL_Rect clyde_r1 = {4, 178, 14, 14}; /**< Right-facing sprite rectangle 1. */
    const SDL_Rect clyde_r2 = {21, 178, 14, 14}; /**< Right-facing sprite rectangle 2. */
    const SDL_Rect clyde_l1 = {38, 178, 14, 14}; /**< Left-facing sprite rectangle 1. */
    const SDL_Rect clyde_l2 = {55, 178, 14, 14};/**< Left-facing sprite rectangle 2. */
    const SDL_Rect clyde_d1 = {106, 178, 14, 14};  /**< Down-facing sprite rectangle 1. */
    const SDL_Rect clyde_d2 = {123, 178, 14, 14};  /**< Down-facing sprite rectangle 2. */
    const SDL_Rect clyde_u1 = {72, 178, 14, 14};/**< Up-facing sprite rectangle 1. */
    const SDL_Rect clyde_u2 = {89, 178, 14, 14};/**< Up-facing sprite rectangle 2. */
};

#endif