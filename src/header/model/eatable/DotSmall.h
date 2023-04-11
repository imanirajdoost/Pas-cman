/**
 * @file DotSmall.h
 * @brief The header file for the DotSmall class, which represents the small dots that Pacman can eat.
 */

#ifndef DOTSMALL_H
#define DOTSMALL_H

#include "Dot.h"

/**
 * @brief The DotSmall class, which represents the small dots that Pacman can eat.
 * 
 * This class inherits from the Dot class.
 */
class DotSmall : public Dot {
public:
    /**
     * @brief The constructor for the DotSmall class.
     */
    DotSmall();

private:
    const SDL_Rect sp_dot_small = {4, 81, 2, 2}; /**< The sprite sheet coordinates for the small dot. */
};

#endif
