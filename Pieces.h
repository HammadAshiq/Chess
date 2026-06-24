#pragma once
#include"Board.h"
#include "Utility.h"
//class Board;
class Pieces
{
protected:
	int sr, sc,er,ec;
	Board* brd;
	COLOUR clr;
public:
	Pieces(int _sr, int _sc, COLOUR _c, Board* _brd);
	virtual void print();
	virtual bool IsLegal(int sr, int sc, int er, int ec, Board* brd,COLOUR c);
	virtual void Move(int sr, int sc, int er, int ec, Board* brd);
	void MakeMovepcs(int er, int ec);
	virtual bool AmIKing();
	bool IsH(int sr, int sc,int er, int ec);
	bool IsV(int sr, int sc, int er, int ec);
	bool IsDignal(int sr, int sc, int er, int ec);
	bool IHC(int sr, int sc, int er, int ec,Board* brd);
	bool IVC(int sr, int sc, int er, int ec,Board* brd);
	bool IDC(int sr, int sc, int er, int ec,Board* brd);
	COLOUR getclr();
};

