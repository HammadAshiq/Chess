#include "King.h"
King::King(int _sr, int _sc, COLOUR c, Board* _brd)
	: Pieces(_sr, _sc, c, _brd)
{
	sr = _sr;
	sc = _sc;
	clr = c;
	brd = _brd;
}
void King::print() {
	if (clr == WHITE) {
		cout << " k ";
	}
	else
		cout << " K ";
}
bool King::AmIKing() {
	return true;
}
void King::Move(int sr, int sc, int er, int ec, Board* brd) {
	brd->SetPiece(er, ec) = brd->SetPiece(sr, sc);
	brd->SetPiece(sr, sc) = nullptr;
}
bool King::IsLegal(int sr, int sc, int er, int ec, Board* brd,COLOUR c) {
	int dr = abs(sr - er);
	int dc = abs(sc - ec);
	if (sc == ec && er == sr) {
		return false;
	}
	/*if(c==WHITE){
		return (brd->GetPiece(0, 4)->IsLegal(sr,sc,er,ec , brd, c) && (dr <= 1 || dc <= 1));
	}
	else {
		return (brd->GetPiece(0, 4)->IsLegal(abs(sr - 7), abs(sc - 7),
			abs(er - 7), abs(ec - 7), brd, c) && (dr <= 1 || dc <= 1));
	}*/
	//return (brd->GetPiece(0, 4)->IsLegal(sr, sc, er, ec, brd, c) && (dr <= 1 || dc <= 1));
	return ((dr <= 1 && dc <= 1) && 
		((IsH(sr, sc, er, ec) && IHC(sr, sc, er, ec, brd)) ||
		(IsV(sr, sc, er, ec) && IVC(sr, sc, er, ec, brd)) ||
		(IsDignal(sr, sc, er, ec) && IDC(sr, sc, er, ec, brd))));
}