#ifndef DOTBIG_H
#define DOTBIG_H

#include "Dot.h"

/**
 * @brief The DotBig class represents the big dots that are eaten by Pacman
 */
class DotBig : public Dot {
public:
    /**
     * @brief Constructs a new DotBig object
     */
    DotBig();

    /**
     * @brief Returns the type of the dot
     * @return The type of the dot
     */
    DotType getDotType() const override;

private:
    /**
     * @brief The sprite rectangle of a big dot
     */
    const SDL_Rect sp_dot_big = { 9,79, 7,7 };
};

#endif
