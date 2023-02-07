#ifndef DOTSMALL_H
#define DOTSMALL_H

#include "Dot.h"

extern SDL_Rect sp_dot_small;

class DotSmall : public Dot {
public:
    DotSmall(int x, int y);
};

#endif