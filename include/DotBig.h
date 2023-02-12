#ifndef DOTBIG_H
#define DOTBIG_H

#include "Dot.h"

static int bigDotHeight = 20;

class DotBig : public Dot {
public:
    DotBig(int x, int y);
    static int getRectHeight();
    void getEaten(const Dot &dot) override;
};

#endif