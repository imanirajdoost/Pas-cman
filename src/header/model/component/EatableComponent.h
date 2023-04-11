/**
* @file EatableComponent.h
* @brief This class is placed on all objects that are eatable by Pacman (such as dots on the screen or fruits or when the ghosts become eatable by Pacman)
*/

#ifndef EATABLECOMPONENT_H
#define EATABLECOMPONENT_H

#include "GameComponent.h"

class EatableComponent : public GameComponent {

public:

    /**
    * @brief Constructor for EatableComponent class
    */
    EatableComponent();

    /**
    * @brief Setter for the index of the object
    * @param indexToSet The index to set for the object
    */
    void setIndex(short indexToSet);

    /**
    * @brief Getter for the index of the object
    * @return The index of the object
    */
    short getIndex() const;

private:
    /**
    * @brief The index of the object
    */
    short index;
};

#endif