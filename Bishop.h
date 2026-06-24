#pragma once
#include "Pieces.h"
#include "Utility"
#include <iostream>
using namespace std;
class Bishop :
    public Pieces
{
public:
    void print();
    Bishop(int _sr, int _sc, COLOUR c, Board* _brd);
    void Move(int sr, int sc, int er, int ec, Board* brd);
    bool IsLegal(int sr, int sc, int er, int ec, Board* brd, COLOUR c);
};

