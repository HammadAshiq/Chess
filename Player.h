#pragma once
#include "Utility.h"
class Player
{
    COLOUR clr;

public:
    Player(COLOUR col) : clr(col) {}
    COLOUR getColor() const { return clr; }
};

