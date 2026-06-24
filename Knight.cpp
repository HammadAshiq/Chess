#include "Knight.h"
Knight::Knight(int _sr, int _sc, COLOUR c, Board* _brd)
	: Pieces(_sr, _sc, c, _brd)
{
	sr = _sr;
	sc = _sc;
	clr = c;
	brd = _brd;
}
void Knight::print() {
	if (clr == WHITE) {
		cout << " h ";
	}
	else
		cout << " H ";
}
void Knight::Move(int sr, int sc, int er, int ec, Board* brd) {
	brd->SetPiece(er, ec) = brd->SetPiece(sr, sc);
	brd->SetPiece(sr, sc) = nullptr;
}
bool Knight::IsLegal(int sr, int sc, int er, int ec, Board* brd, COLOUR c) {
	int dr = abs(sr - er);
	int dc = abs(sc - ec);
	return ((dr == 2 && dc == 1) || (dr == 1 && dc == 2));
}