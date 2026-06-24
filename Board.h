#pragma once
#include "Utility.h"
class Pieces;
class Board
{
	Pieces* Ps[8][8];
	//COLOUR clr;
public:
	Board();
	void init();
	void print();
	Pieces* GetPiece(int _i, int _j);
	Pieces*& SetPiece(int _i, int _j);
	void MakeMovebrd(int sr, int sc, int er, int ec);
	void MoveMade(int sr, int sc, int er, int ec,Board* brd);
	bool LegalCheck(int sr, int sc, int er, int ec,Board* _brd,COLOUR c);

};

