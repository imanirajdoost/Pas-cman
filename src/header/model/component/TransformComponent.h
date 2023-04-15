/**
 * @file TransformComponent.h
 * @brief Class that handles an object's size and position on the screen. All game objects have this component attached.
 */
#ifndef PAS_CMAN_TRANSFORMCOMPONENT_H
#define PAS_CMAN_TRANSFORMCOMPONENT_H

#include <SDL2/SDL_rect.h>
#include "GameComponent.h"

class TransformComponent : public GameComponent {
public:
    /**
     * @brief Default constructor for TransformComponent class.
     */
    TransformComponent();

    /**
     * @brief Constructor for TransformComponent class.
     * @param initPos The initial position of the object.
     */
    TransformComponent(SDL_Rect initPos);

    /**
    * @brief Constructor for TransformComponent class.
    * @param posX The x-coordinate of the object's position on the screen.
    * @param posY The y-coordinate of the object's position on the screen.
    * @param sizeWidth The width of the object on the screen.
    * @param sizeHeight The height of the object on the screen.
    */
    TransformComponent(int posX, int posY, int sizeWidth, int sizeHeight);

    /**
    * @brief Setter for the object's position on the screen.
    * @param x The new x position.
    * @param y The new y position.
    */
    void setPos(int x, int y);

    /**
    * @brief Getter for the rectangle that defines the object's position and size.
    * @return The rectangle representing the object's position and size.
    */
    SDL_Rect getRect() const;

    /**
    * @brief Getter for the object's x-coordinate on the screen.
    * @return The object's x-coordinate.
    */
    int getX() const;

    /**
    * @brief Getter for the object's y-coordinate on the screen.
    * @return The object's y-coordinate.
    */
    int getY() const;

    /**
    * @brief Getter for the x-coordinate of the tile that the object is in.
    * @return The x-coordinate of the tile.
    */
    int getTileX() const;

    /**
    * @brief Getter for the y-coordinate of the tile that the object is in.
    * @return The y-coordinate of the tile.
    */
    int getTileY() const;

    /**
    * @brief Setter for the object's x-coordinate on the screen.
    * @param x The new x-coordinate.
    */
    void setX(int x);

    /**
    * @brief Setter for the object's y-coordinate on the screen.
    * @param y The new y-coordinate.
    */
    void setY(int Y);

    /**
    * @brief Getter for the rectangle that defines the object's position and size after it has been transformed for drawing.
    * @return The rectangle representing the object's position and size after transformation for drawing.
    */
    SDL_Rect getDrawRect() const;

protected:
    SDL_Rect rect; ///< The rectangle that defines the object's position and size.

    /**
    * @brief Setter for the object's size.
    * @param x The new width of the object.
    * @param y The new height of the object.
    */
    void setSize(int x, int y);
};

#endif //PAS_CMAN_TRANSFORMCOMPONENT_H
