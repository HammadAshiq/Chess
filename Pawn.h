#pragma once
#include "Pieces.h"
#include "Utility"
#include <iostream>
using namespace std;
class Pawn :
    public Pieces
{
    bool hasMoved=false;
public:
    void print();
    void Move(int sr, int sc, int er, int ec, Board* brd);
    Pawn(int _sr, int _sc, COLOUR c, Board* _brd);
    bool IsLegal(int sr, int sc, int er, int ec, Board* brd, COLOUR c);
};

