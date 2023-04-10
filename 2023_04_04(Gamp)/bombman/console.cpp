#include "console.h"

void FullScreen()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE),
		CONSOLE_FULLSCREEN_MODE,0);
}

void Gotoxy(int x, int y)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cur = { x,y };
	SetConsoleCursorPosition(hOut, cur);
}

BOOL GotoxyBOOL(int x, int y)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cur = { x,y };
	return SetConsoleCursorPosition(hOut, cur);
}

void GotoxyPlayer(int x, int y)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cur = { x *  2,y};
	SetConsoleCursorPosition(hOut, cur);
}

void ConsoleCursor(bool _bvis, DWORD _dwSize)
{
	CONSOLE_CURSOR_INFO curinfo;
	curinfo.bVisible = _bvis;
	curinfo.dwSize = _dwSize;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo);
}

void SetColor(int color, int bgcolor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

int GetColor()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	int color = info.wAttributes;
	return color;
}

int GetbgColor()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	int color = info.wAttributes >> 4;
	return color;
}