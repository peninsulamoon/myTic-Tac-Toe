#include"tictactoe.h"

tictactoe::tictactoe()
{
	ox_turn = true;
	gameOver = playing;
	turns = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			board[i][j] = '.';
}

bool tictactoe::win(const int& x, const int& y)
{
	char symbol = ox_turn ? 'o' : 'x';
	if (board[(x + 1) % 3][y] == symbol && board[(x + 2) % 3][y] == symbol)
		return true;
	if (board[x][(y+1)%3] == symbol && board[x][(y + 2) % 3] == symbol)
		return true;
	if (x==y&& board[(x + 1) % 3][(y + 1) % 3] == symbol && board[(x + 2) % 3][(y + 2) % 3] == symbol)
		return true;
	if (x + y==2 && board[(x + 1) % 3][(y - 1) % 3] == symbol && board[(x + 2) % 3][(y - 2) % 3] == symbol)
		return true;
	return false;
}

void tictactoe::takingTurn(const int& x, const int& y)
{
	if (board[x][y] == 'o' || board[x][y] == 'x')
		return;
	board[x][y] = ox_turn ? 'o' : 'x';
	if (win(x, y))
	{
		gameOver = ox_turn ? owin : xwin;
		return;
	}
	turns++;
	if (turns == 9)
	{
		gameOver = draw;
		return;
	}
	ox_turn = !ox_turn;
}

result tictactoe::getResult()
{
	return gameOver;
}