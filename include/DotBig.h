#ifndef DOTBIG_H
#define DOTBIG_H

#include "Eatable.h"

static int bigDotHeight = 20;

class DotBig : public Eatable {
public:
    DotBig(int x, int y);
    static int getRectHeight();
    void getEaten(const Eatable &dot) override;
};

#endif