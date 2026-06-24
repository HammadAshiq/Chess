#include "Pieces.h"
#include "Board.h"
#include <iostream>
using namespace std;
Pieces::Pieces(int _sr, int _sc, COLOUR c, Board* _brd) {

}
void Pieces::print() {
}
bool Pieces::IsLegal(int sr, int sc, int er, int ec, Board* brd,COLOUR c) {

	return true;
}
bool Pieces::IsH(int sr, int sc, int er, int ec) {
	return sr == er;
}
bool Pieces::IsV(int sr, int sc, int er, int ec) {
	return sc == ec;
}
bool Pieces::IsDignal(int sr, int sc, int er, int ec) {
	int dr = abs(sr - er);
	int dc = abs(ec - sc);
	return dr == dc;
}
bool Pieces::IHC(int sr, int sc, int er, int ec,Board* brd) {
	for (int i = min(sc,ec)+1; i < max(sc,ec); i++)
	{
		if (brd->GetPiece(sr,i) != nullptr) {
			return false;
		}
	}
	return true;
}
bool Pieces::IVC(int sr, int sc, int er, int ec,Board* brd){
	for (int i = min(sr, er) + 1; i < max(sr, er); i++)
	{
		if (brd->GetPiece(i,sc) != nullptr) {
			return false;
		}
	}
	return true;
}
bool Pieces::IDC(int sr, int sc, int er, int ec,Board* brd) {
	int dc = abs(ec - sc);
	int dr = abs(er - sr);
	if ((er > sr) && (ec > sc)) {
		for (int i = 1; i < dc; i++)
		{
			if (brd->GetPiece(sr + 1, sc + 1) != nullptr) {
				return false;
			}
		}
		return true;
	}
	if ((er < sr) && (ec > sc)) {
		for (int i = 1; i < dc; i++)
		{
			if (brd->GetPiece(sr - i, sc + i) != nullptr) {
				return false;
			}
		}
		return true;
	}
	if ((er > sr) && (ec < sc)) {
		for (int i = 1; i < dc; i++)
		{
			if (brd->GetPiece(sr + i, sc - i) != nullptr) {
				return false;
			}
		}
		return true;
	}
	if ((er < sr)&& (ec < sc)) {
		for (int i = 1; i < dc; i++)
		{
			if (brd->GetPiece(sr - i, sc - i) != nullptr) {
				return false;
			}
		}
		return true;
	}
	return false;
}
COLOUR Pieces::getclr() {
	return this->clr;
}
void Pieces::MakeMovepcs(int er, int ec){
	sr = er;
	sc = ec;
}
void Pieces::Move(int sr,int sc,int er, int ec,Board* brd) {
}
bool Pieces::AmIKing() {
	return false;
}