#include "Queen.h"
Queen::Queen(int _sr, int _sc, COLOUR c, Board* _brd)
	: Pieces(_sr, _sc, c, _brd)
{
	sr = _sr;
	sc = _sc;
	clr = c;
	brd = _brd;
}
void Queen::print() {
	if (clr == WHITE) {
		cout << " q ";
	}
	else
		cout << " Q ";
}
void Queen::Move(int sr, int sc, int er, int ec, Board* brd) {
	brd->SetPiece(er, ec) = brd->SetPiece(sr, sc);
	brd->SetPiece(sr, sc) = nullptr;
}
bool Queen::IsLegal(int sr, int sc, int er, int ec, Board* brd, COLOUR c) {
	/*if (c == WHITE) {
		return (brd->GetPiece(0, 0)->IsLegal(sr,sc,er,ec, brd, c)
			|| brd->GetPiece(0, 3)->IsLegal(sr,sc,er,ec , brd, c));
	}
	else {
		return (brd->GetPiece(0, 0)->IsLegal(abs(sr - 7), abs(sc - 7), abs(er - 7), abs(ec - 7), brd, c)
			|| brd->GetPiece(0, 3)->IsLegal(abs(sr - 7), abs(sc - 7), abs(er - 7), abs(ec - 7), brd, c));
	}*/

	/*return (brd->GetPiece(0, 0)->IsLegal(sr, sc, er, ec, brd, c)
		|| brd->GetPiece(0, 3)->IsLegal(sr, sc, er, ec, brd, c));*/
	return ((IsH(sr, sc, er, ec) && IHC(sr, sc, er, ec, brd)) ||
		(IsV(sr, sc, er, ec) && IVC(sr, sc, er, ec, brd)) || 
		(IsDignal(sr, sc, er, ec) && IDC(sr, sc, er, ec, brd)));
}