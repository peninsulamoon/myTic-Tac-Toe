#include<graphics.h>
#include"tictactoe.h"
#include<stdio.h>

void drawBoard(const tictactoe ttt)
{
	line(590, 210, 590, 510);
	line(690, 210, 690, 510);
	line(490, 310, 790, 310);
	line(490, 410, 790, 410);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			if (ttt.board[j][i] == 'o')
			{
				circle(540 + 100 * i, 260 + 100 * j, 50);
			}
			if (ttt.board[j][i] == 'x')
			{
				line(490+100*i,210+100*j,590+100*i,310+100*j);
				line(490 + 100 * i, 310 + 100 * j, 590 + 100 * i, 210 + 100 * j);
			}
		}
	}
}

void drawTipText(const tictactoe& ttt)
{
	static TCHAR str[64];
	_stprintf_s(str, _T("当前棋子类型：%c"), ttt.ox_turn ? 'o' : 'x');

	settextcolor(RGB(225, 175, 45));
	outtextxy(0, 0, str);

}

int main()
{
	initgraph(1280, 720);
	int x = 0;
	int y = 0;
	tictactoe ttt;
	BeginBatchDraw();
	cleardevice();
	drawTipText(ttt);
	drawBoard(ttt);
	FlushBatchDraw();
	while (true)
	{
		DWORD start_time = GetTickCount();
		ExMessage msg;
		//接受消息
		
		while (peekmessage(&msg))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				y = msg.x;
				x = msg.y;
			}
		}
		//数据处理
		if (x < 210 || x>510 || y < 490 || y>790)
			continue;
		x = (x - 210) / 100;
		y = (y - 490) / 100;
		ttt.takingTurn(x, y);

		//图像绘制
		cleardevice();
		drawBoard(ttt);
		drawTipText(ttt);
		FlushBatchDraw();
		if (ttt.gameOver == owin) {
			MessageBox(GetHWnd(), _T("o获胜！"), _T("结束"), MB_OK); break;
		}
		if (ttt.gameOver == xwin) {
			MessageBox(GetHWnd(), _T("x获胜！"), _T("结束"), MB_OK); break;
		}
		if (ttt.gameOver == draw) {
			MessageBox(GetHWnd(), _T("平局！"), _T("结束"), MB_OK); break;
		}
		DWORD end_time = GetTickCount();
		DWORD delta_time = end_time - start_time;
		if (delta_time < 1000 / 30)
		{
			Sleep(1000 / 30-delta_time);
		}
	}
	EndBatchDraw();
	return 0;
}
