#pragma once
#include "Board.h"
#include "Player.h"
#include "Pieces.h"
#include "Utility.h"
#include <iostream>
using namespace std;
class Chess
{
	bool HPs[8][8]={};
	char CB[8][8] = {};
	Board board;
	Player plr_1;
	Player plr_2;
	Player* Turn;
	int sr, sc, er, ec,temp;
	bool IsCheck,Terminate,No_check;
	int temp_sr,temp_sc, temp_er, temp_ec;
public:
	Chess();
	void play();
	bool IsValidstrt(Board& board, int sr, int sc, COLOUR c);
	bool IsValidDst(Board& board, int &er, int &ec, COLOUR c);
	void CompHPs(Board& board, int sr, int sc, bool H[][8], COLOUR c,bool _Terminate,bool IsCheck);
	void UnHighlight(Board& board, int sr, int sc, bool H[][8], COLOUR c);
	bool FindKing(Board& _board, int& kr, int& kc, COLOUR c);
	bool Check(Board& _board, COLOUR c);
	void undoMove(Board* _board, int sr, int sc, int er, int ec, Pieces* p);
	bool SelfCheck(Board& _board, int _sr, int _sc, int _er, int _ec, COLOUR _c);
	bool Checkmate(Board& _board, COLOUR _c);
	bool Stalemate(Board& _board, COLOUR _c);
	bool CheckAvailableMoves(Board& _board, COLOUR _c);
	bool PiecCanRemCheck(Board& _board, int _sr, int _sc, COLOUR c,bool IsCheck);
	void Highlight(bool HPs[][8], char CB[][8]);
	void RemHighlight(bool HPs[][8], char CB[][8]);
	void CB_init(char Ps[][8]);
	void CB_print(char Ps[][8], bool HPs[][8]);
	void CB_Move(char Ps[][8], int sr, int sc, int er, int ec);
	//void MakeMove(Board& board, int sr, int sc, int er, int ec);
};

