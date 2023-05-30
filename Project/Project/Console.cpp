#include "Console.h"

void Gotoxy(int x, int y)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Cur = { x, y };
	SetConsoleCursorPosition(hOut, Cur);
}

void Gotoxyplayer(int x, int y)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Cur = { x * 2, y };
	SetConsoleCursorPosition(hOut, Cur);
}

void ConsoleCursor(bool _bVis, DWORD _dwSize)
{
	CONSOLE_CURSOR_INFO curinfo;
	curinfo.bVisible = _bVis;
	curinfo.dwSize = _dwSize;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo);
}