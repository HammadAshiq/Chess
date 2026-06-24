#include "Pawn.h"
Pawn::Pawn(int _sr, int _sc, COLOUR c, Board* _brd)
	: Pieces(_sr, _sc, c, _brd)
{
	sr = _sr;
	sc = _sc;
	clr = c;
	brd = _brd;
}
void Pawn::print() {
	if (clr == WHITE) {
		cout << " p ";
	}
	else
		cout << " P ";
}
void Pawn::Move(int sr, int sc, int er, int ec, Board* brd) {
    brd->SetPiece(er, ec) = brd->SetPiece(sr, sc);
    brd->SetPiece(sr, sc) = nullptr;
    hasMoved = true;
}
bool Pawn::IsLegal(int sr, int sc, int er, int ec, Board* brd, COLOUR c) {
	/*int dr = abs(sr - er);
	int dc = abs(sc - ec);
	return (dr == 2 && dc == 1) || (dr == 1 && dc == 2);*/
	/*if (IsFirst == true) {

	}
	return false;*/
    int dir = (c ==WHITE) ? -1 : 1;
    if (sc == ec) {
        if (er == sr + dir) {
            if (brd->GetPiece(er,ec) == nullptr) {
                return true;
            }
        }
        else if (er == sr + (2 * dir)) {
            if (!hasMoved && brd->GetPiece(sr + dir,sc) == nullptr && brd->GetPiece(er, ec) == nullptr){
                return true;
            }
        }
    }
    if (abs(ec - sc) == 1 && er == sr + dir) {
        if (brd->GetPiece(er,ec) != nullptr && brd->GetPiece(er,ec)->getclr() != c) {
            return true;
        }
    }

    return false;
}