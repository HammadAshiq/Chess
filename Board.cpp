#include "Board.h"
#include "Pawn.h"
#include "King.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Utility.h"
#include "Queen.h"
#include <iostream>
using namespace std;
Board::Board() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Ps[i][j] = nullptr;
        }
    }
}
void Board::init() {
    for (int r = 0; r < 8; r++)
    {
        for (int c = 0; c < 8; c++)
        {
            if (r == 1) {
                Ps[r][c] = new Pawn(r, c, BLACK, this);
            }
            else if (r == 6) {
                Ps[r][c] = new Pawn(r, c, WHITE, this);
            }
            else if (r == 0 && c == 4) {
                Ps[r][c] = new King(r, c, BLACK, this);
            }
            else if (r == 7 && c == 4) {
                Ps[r][c] = new King(r, c, WHITE, this);
            }
            else if (r == 0 && c == 3) {
                Ps[r][c] = new Queen(r, c, BLACK, this);
            }
            else if (r == 7 && c == 3) {
                Ps[r][c] = new Queen(r, c, WHITE, this);
            }
            else if (r == 0 && (c == 0 || c==7)) {
                Ps[r][c] = new Rook(r, c, BLACK, this);
            }
            else if (r == 7 && (c == 0 || c==7)) {
                Ps[r][c] = new Rook(r, c, WHITE, this);
            }
            else if (r == 0 && (c == 2 || c == 5)) {
                Ps[r][c] = new Bishop(r, c, BLACK, this);
            }
            else if (r == 7 && (c == 2 || c == 5)) {
                Ps[r][c] = new Bishop(r, c, WHITE, this);
            }
            else if (r == 0 && (c == 1 || c == 6)) {
                Ps[r][c] = new Knight(r, c, BLACK, this);
            }
            else if (r == 7 && (c == 1 || c == 6)) {
                Ps[r][c] = new Knight(r, c, WHITE, this);
            }
        }
    }
}
void Board::print() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (Ps[i][j] == nullptr) {
                cout << " - ";
            }
            else{
                Ps[i][j]->print();
            }
        }
        cout << endl;
    }
    cout << "CLICK to undo";
}
Pieces* Board::GetPiece(int _i, int _j) {
    return this->Ps[_i][_j];
}
Pieces*& Board::SetPiece(int _i, int _j) {
    return this->Ps[_i][_j];
}
void Board::MakeMovebrd(int sr, int sc, int er, int ec) {
    Ps[sr][sc]->MakeMovepcs(er,ec);
    Ps[er][ec] = Ps[sr][sc];
    Ps[sr][sc] = nullptr;
}
void Board::MoveMade(int sr, int sc, int er, int ec,Board* brd) {
    Ps[sr][sc]->Move(sr, sc, er, ec,brd);
}
bool Board::LegalCheck(int sr, int sc, int er, int ec,Board* brd,COLOUR c) {
    /*if (c == BLACK)
        return Ps[sr][sc]->IsLegal(sr, sc, er, ec, brd,c);
    else 
        return Ps[sr][sc]->IsLegal(abs(sr-7), abs(sc-7), abs(er-7), abs(ec-7), brd,c);*/
    return Ps[sr][sc]->IsLegal(sr, sc, er, ec, brd, c);
}

