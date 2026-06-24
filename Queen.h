#pragma once
#include "Pieces.h"
#include "Bishop.h"
#include "Rook.h"
#include "Utility"
#include <iostream>
using namespace std;
class Queen :
    public Pieces
{
public:
    void print();
    Queen(int _sr, int _sc, COLOUR c, Board* _brd);
    bool IsLegal(int sr, int sc, int er, int ec, Board* brd, COLOUR c);
    void Move(int sr, int sc, int er, int ec, Board* brd);
};

