#ifndef DOTBIG_H
#define DOTBIG_H

#include "Dot.h"

class DotBig : public Dot {
public:
    DotBig();
private:
    const SDL_Rect sp_dot_big = { 9,79, 7,7 };
};

#endif