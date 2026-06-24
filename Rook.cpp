#include "Rook.h"
Rook::Rook(int _sr, int _sc, COLOUR c, Board* _brd)
	: Pieces(_sr, _sc, c, _brd)
{
	sr = _sr;
	sc = _sc;
	clr = c;
	brd = _brd;
}
void Rook::print() {
	if (clr == WHITE) {
		cout << " r ";
	}
	else
		cout << " R ";
}
void Rook::Move(int sr, int sc, int er, int ec, Board* brd) {
	brd->SetPiece(er, ec) = brd->SetPiece(sr, sc);
	brd->SetPiece(sr, sc) = nullptr;
}
bool Rook::IsLegal(int sr, int sc, int er, int ec, Board* brd, COLOUR c) {
	/*if (c == WHITE) {
		return (IsH(sr, sc, er, ec) && IHC(sr, sc, er, ec, brd)) ||
			(IsV(sr, sc, er, ec) && IVC(sr, sc, er, ec, brd));
	}
	else {
		return (IsH(abs(sr - 7), abs(sc - 7), abs(er - 7), abs(ec - 7)) && 
			IHC(abs(sr - 7), abs(sc - 7), abs(er - 7), abs(ec - 7), brd) ||
			(IsV(abs(sr - 7), abs(sc - 7), abs(er - 7), abs(ec - 7)) && 
				IVC(abs(sr - 7), abs(sc - 7), abs(er - 7), abs(ec - 7), brd)));
	}*/
	return (IsH(sr, sc, er, ec) && IHC(sr, sc, er, ec, brd)) ||
		(IsV(sr, sc, er, ec) && IVC(sr, sc, er, ec, brd));
}