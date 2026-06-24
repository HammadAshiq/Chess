#include "Chess.h"
Chess::Chess():plr_1(WHITE), plr_2(BLACK) {
	Turn = &plr_1;
}
void Chess::play() {
	board.init();
	CB_init(CB);
	system("cls");
	CB_print(CB,HPs);
	//board.print();
	do {
		//sr = 0, sc = 0, er = 0, ec = 0, temp = 0;
		cout << (Turn->getColor() == WHITE ? "  White" : "   Black") << "'s Turn" << endl;
		do {
			do {
				do {
					//n:
					//system("cls");
					//CB_print(CB,HPs);
					if (Check(board, Turn->getColor())) {
						IsCheck = true;
					}
					else
						IsCheck = false;
					getRowColbyLeftClick(sr, temp);
					sc = (temp) / 2;
					//cout << sr << "  " << sc << endl;
					//Pieces* temp = board.SetPiece(temp_er, temp_ec);
					/*if (sr == 9 && sc == (0 || 1 || 2)) {
						undoMove(&board, temp_sr, temp_sc, temp_er, temp_ec, temp);
						goto n;
					}*/
					CompHPs(board,sr,sc,HPs,Turn->getColor(),&Terminate,IsCheck);
					if (Terminate == true) {
						Terminate = false;
						continue;
					}
					//Highlight(HPs, CB);
					system("cls");
					CB_print(CB,HPs);
				} while (!PiecCanRemCheck(board,sr,sc, Turn->getColor(), IsCheck));
				//!IsValidstrt(board, HPs, sr, sc, Turn->getColor())
				//er = 0, ec = 0, temp = 0;
				//system("cls");
				//CB_print(CB,HPs);
				//cout << "Enter End coordinate: ";
				getRowColbyLeftClick(er, temp);
				ec = (temp) /2;
				//cout << er << "  " << ec << endl;
				//HPs[8][8] = false;
				RemHighlight(HPs, CB);
				//system("cls");
				//CB_print(CB,HPs);
			} while (!SelfCheck(board,sr,sc,er,ec,Turn->getColor()));
			//!IsValidDst(board, er, ec, Turn->getColor())
			//cout << "Good"<<endl;
			//break;
		} while (!board.LegalCheck(sr,sc,er,ec,&board,Turn->getColor()));
		//board.MakeMovebrd(sr, sc, er, ec);
		temp_sr = sr, temp_sc = sc;
		temp_er = er, temp_sc = ec;
		board.MoveMade(sr, sc, er, ec, &board);
		CB_Move(CB, sr, sc, er, ec);
		////HPs[8][8] = {};
		system("cls");
		CB_print(CB,HPs);
		//board.print();
		Turn = ((Turn == &plr_1) ? &plr_2 : &plr_1);
		if (Check(board, Turn->getColor())) {
			if (CheckAvailableMoves(board, Turn->getColor())) {
				Turn = ((Turn == &plr_1) ? &plr_2 : &plr_1);
				cout << (Turn->getColor() == WHITE ? "  White" : "   Black") << " has WON!!!!" << endl;
				break;
				//Checkmate(board, Turn->getColor())
			}
				
		}
		else {
			if (CheckAvailableMoves(board, Turn->getColor())) {
				cout << "Stalemate!!" << endl;
				break;
				//Stalemate(board, Turn->getColor()
			}
		}
	} while (true);
}
bool Chess::IsValidstrt(Board& board, int sr,int sc,COLOUR c) {
	if ((sr < 0 && sr > 7) && (sc < 0 && sc > 7)) {
		return false;
	}
	if (board.GetPiece(sr, sc) == nullptr) {
		return false;
	}
	else if (board.GetPiece(sr, sc)->getclr() == c) {
		//this->CompHPs(board, sr, sc, HPs, c);
		return true;
	}
	else
		return false;
}
bool Chess::IsValidDst(Board& board, int &er, int &ec, COLOUR c) {
	if ((er < 0 && er > 7) && (ec < 0 && ec > 7)) {
		return false;
	}
	if (board.GetPiece(er, ec) == nullptr) {
		return true;
	}
	else if (board.GetPiece(er, ec)->getclr() == c)
		return false;
	else
		return true;
}
void Chess::CompHPs(Board& board, int sr, int sc, bool H[][8], COLOUR c, bool _Terminate, bool IsCheck) {
	/*if (board.GetPiece(sr, sc)==nullptr && board.GetPiece(sr, sc)->getclr() != c) {
		return;
	}*/
	if (!IsValidstrt(board, sr, sc, c)){
		_Terminate = true;
		return;
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.LegalCheck(sr, sc, i, j, &board, c) && board.GetPiece(i, j) == nullptr && 
				SelfCheck(board, sr, sc, i, j, c))
			{
				H[i][j] = true;
			}
		}
	}
}//PiecCanRemCheck(board, sr, sc, c, IsCheck) == true 
void Chess::UnHighlight(Board& board, int sr, int sc, bool H[][8], COLOUR c) {
	//H[8][8] = {};
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (H[i][j]==true)
			{
				H[i][j] = false;
			}
		}
	}
}
bool Chess::FindKing(Board& _board, int& kr, int& kc,COLOUR _c) {
	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 8; c++) {
			if (_board.GetPiece(r, c) !=nullptr && 
				_board.GetPiece(r,c)->getclr() == _c &&
				_board.GetPiece(r, c)->AmIKing() == true) {

				kr = r;
				kc = c;
				return true;
			}
		}
	}
	return false;
}
bool Chess::PiecCanRemCheck(Board& _board, int _sr, int _sc, COLOUR _c,bool IsCheck) {
	if (!IsValidstrt(_board, _sr, _sc, _c)) {
		return false;
	}
	if (!IsCheck) {
		return true;
	}
	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 8; c++) {
			if (IsValidDst(board, r, c, Turn->getColor()) == true &&
				_board.LegalCheck(_sr, _sc, r, c, &board, Turn->getColor()) == true &&
				!SelfCheck(_board,_sr,_sc,r,c,_c)) {
				return true;
			}
		}
	}
	return false;
}
void Chess::undoMove(Board* _board, int sr, int sc, int er, int ec, Pieces* p) {
	_board->SetPiece(sr, sc) = _board->SetPiece(er, ec);
	_board->SetPiece(er, ec) = p;
}
bool Chess::Check(Board& _board, COLOUR _c) {
	int kr, kc;
	COLOUR clr=WHITE;
	if (_c == WHITE) {
		clr = BLACK;
	}
	if (FindKing(_board, kr, kc, _c)) {
		for (int r = 0; r < 8; r++) {
			for (int c = 0; c < 8; c++) {
				if (IsValidstrt(board, r, c, clr)==true &&
					_board.LegalCheck(r, c, kr, kc, &board, clr)==true) {
					return true;
				}
			}
		}
		return false;
	}
}
bool Chess::SelfCheck(Board& _board, int _sr, int _sc, int _er, int _ec, COLOUR _c) {
	if (!IsValidDst(_board, _er, _ec, _c)) {
		return false;
	}
	/*if (!Check(_board, _c)) {
		return true;
	}*/
	Pieces* temp = _board.GetPiece(_er, _ec);
	//board.MoveMade(sr, sc, er, ec, &board);
	board.MakeMovebrd(_sr, _sc, _er, _ec);
	if (!Check(_board, _c)) {
		undoMove(&_board,_sr,_sc,_er,_ec,temp);
		return true;
	}
	else {
		undoMove(&_board, _sr, _sc, _er, _ec, temp);
		//cout << "Invalid SelfCeck Will Accourr" << endl;
		return false;
	}
}
bool Chess::Checkmate(Board& _board,COLOUR _c) {
	//int kr, kc;
	//FindKing(_board, kr, kc, _c);
	/*for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 8; c++) {
			if (IsValidstrt(_board, r, c, _c)&&
				PiecCanRemCheck(_board, r, c, _c, true)) {
				return false;
			}
		}
	}*/
	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 8; c++) {
			if (IsValidstrt(_board, r, c, _c)) {
				for (int i = 0; i < 8; i++) {
					for (int j = 0; j < 8; j++) {
						if (IsValidDst(_board, i, j, _c)&&
							_board.LegalCheck(r, c, i, j, &_board, _c)&&
							SelfCheck(_board, r, c, i, j, _c)) {
							return false;
						}
					}
				}
			}
		}
	}
	return true;
}
bool Chess::CheckAvailableMoves(Board& _board, COLOUR _c) {
	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 8; c++) {
			if (IsValidstrt(_board, r, c, _c)) {
				for (int i = 0; i < 8; i++) {
					for (int j = 0; j < 8; j++) {
						if (IsValidDst(_board, i, j, _c) &&
							_board.LegalCheck(r, c, i, j, &_board, _c) &&
							SelfCheck(_board, r, c, i, j, _c)) {
							return false;
						}
					}
				}
			}
		}
	}
}
bool Chess::Stalemate(Board& _board, COLOUR _c) {
	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 8;c++) {
			if (_board.GetPiece(r,c)!=nullptr && _board.GetPiece(r,c)->getclr() == _c) {
				for (int i = 0; i < 8; i++) {
					for (int j = 0; j < 8; j++) {
						if (_board.GetPiece(i, j) != nullptr &&
							_board.GetPiece(i, j)->getclr() == _c &&
							IsValidDst(_board, i, j, _c) &&
							_board.LegalCheck(r, c, i, j, &_board, _c) &&
							SelfCheck(_board,r, c, i, j, _c)) {
							return true;
						}
					}
				}
			}
		}
	}
	/*IsValidstrt(board, r, c, _c) &&
	IsValidDst(_board, i, j, _c) &&
	_board.LegalCheck(r, c, i, j, &_board, _c) &&*/
	return false;
}
void Chess::Highlight(bool HPs[][8],char CB[][8]) {
	/*for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (HPs[i][j] == true) {
				CB[i][j] = 'X';
			}
		}
	}*/
}
void Chess::RemHighlight(bool HPs[][8], char CB[][8]) {
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			HPs[i][j] = false;
		}
	}
}
void Chess::CB_Move(char Ps[][8], int sr, int sc, int er, int ec ) {
	if (Ps[er][ec] == '-') {
		swap(Ps[er][ec], Ps[sr][sc]);
	}
	else {
		swap(Ps[er][ec], Ps[sr][sc]);
		Ps[sr][sc] = '-';
	}
}
void Chess::CB_print(char Ps[][8], bool HPs[][8]) {
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (HPs[i][j])
				cout << "X"<<" ";
			else
				cout << Ps[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	//cout << "CLICK TO UNDO" << endl;
}
void Chess::CB_init(char Ps[][8]) {
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			if (r == 1) {
				Ps[r][c] = 'p';
			}
			else if (r == 6) {
				Ps[r][c] = 'P';
			}
			else if (r == 0 && c == 4) {
				Ps[r][c] = 'K';
			}
			else if (r == 7 && c == 4) {
				Ps[r][c] = 'k';
			}
			else if (r == 0 && c == 3) {
				Ps[r][c] = 'Q';
			}
			else if (r == 7 && c == 3) {
				Ps[r][c] = 'q';
			}
			else if (r == 0 && (c == 0 || c == 7)) {
				Ps[r][c] = 'R';
			}
			else if (r == 7 && (c == 0 || c == 7)) {
				Ps[r][c] = 'r';
			}
			else if (r == 0 && (c == 2 || c == 5)) {
				Ps[r][c] = 'B';
			}
			else if (r == 7 && (c == 2 || c == 5)) {
				Ps[r][c] = 'b';
			}
			else if (r == 0 && (c == 1 || c == 6)) {
				Ps[r][c] = 'H';
			}
			else if (r == 7 && (c == 1 || c == 6)) {
				Ps[r][c] = 'h';
			}
			else
				Ps[r][c] = '-';
		}
		cout << endl;
	}
}
