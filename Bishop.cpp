#include "Bishop.h"
Bishop::Bishop(int _sr, int _sc, COLOUR c, Board* _brd)
	: Pieces(_sr, _sc, c, _brd)
{
	sr = _sr;
	sc = _sc;
	clr = c;
	brd = _brd;
}
void Bishop::print() {
	if (clr == WHITE) {
		cout << " b ";
	}
	else
		cout << " B ";
}
void Bishop::Move(int sr, int sc, int er, int ec, Board* brd) {
	brd->SetPiece(er, ec) = brd->SetPiece(sr, sc);
	brd->SetPiece(sr, sc) = nullptr;
}
bool Bishop::IsLegal(int sr, int sc, int er, int ec, Board* brd, COLOUR c) {
	/*if(c==WHITE)
		return (IsDignal(sr, sc, er, ec) && IDC(sr, sc, er, ec, brd));
	else
		return (IsDignal(abs(sr-7), abs(sc-7), abs(er-7), abs(ec-7)) && 
			IDC(abs(sr - 7), abs(sc - 7), abs(er - 7), abs(ec - 7), brd));*/
	return (IsDignal(sr, sc, er, ec) && IDC(sr, sc, er, ec, brd));
}