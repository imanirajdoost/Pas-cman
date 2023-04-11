//
// Created by iman on 14/03/23.
//

#ifndef PAS_CMAN_ANIMATIONMODEL_H
#define PAS_CMAN_ANIMATIONMODEL_H

#include <SDL2/SDL_rect.h>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Class that represents a single animation for a game object
 */
class AnimationModel {
private:
    /** @brief name of the animation */
    string name;

    /** @brief wheather or not the animation should loop */
    bool should_loop;

public:
    /**
     * @brief Constructor for AnimationModel class
     * @param shouldLoop Specifies whether the animation should loop or not
     */
    explicit AnimationModel(bool shouldLoop);

    /**
     * @brief Getter for the list of sprites in the animation
     * @return Vector of SDL_Rect objects representing the position and size of each sprite in the animation
     */
    vector<SDL_Rect> getSpritesList() const;

    /**
     * @brief Add a single sprite to the animation
     * @param sp SDL_Rect object representing the position and size of the sprite
     */
    void addSprite(const SDL_Rect &sp);

    /**
     * @brief Add multiple sprites to the animation
     * @param sps Vector of SDL_Rect objects representing the position and size of each sprite to add to the animation
     */
    void addSprites(const vector<SDL_Rect> &sps);

    /**
     * @brief Getter for the name of the animation
     * @return String representing the name of the animation
     */
    string getName() const;

    /**
     * @brief Getter for the should_loop variable of the animation
     * @return Boolean value representing whether the animation should loop or not
     */
    bool getLoop() const;

    /**
     * @brief Setter for the name of the animation
     * @param newName New name for the animation
     */
    void setName(const string &newName);

    /** @brief list of the sprites used in the animation */
    vector<SDL_Rect> sprites_list;
};

#endif //PAS_CMAN_ANIMATIONMODEL_H
