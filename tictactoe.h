#pragma once

enum result{
	owin, xwin, draw, playing
};

class tictactoe
{
public:
	tictactoe();
	bool win(const int &x, const int &y);
	void takingTurn(const int& x, const int& y);
	result getResult();

public:
	//TRUE for 'o', FALSE for 'x'.
	bool ox_turn; 
	//3*3 chessboard.
	char board[3][3];
	
	result gameOver;
	int turns;
};