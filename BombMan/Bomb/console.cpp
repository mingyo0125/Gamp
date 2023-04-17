#include "console.h"
void FullScreen()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE)
		, CONSOLE_FULLSCREEN_MODE, 0);
}

BOOL Gotoxy(int x, int y)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Cur = { x,y };
	return SetConsoleCursorPosition(hOut, Cur);
}

void Gotoxyplayer(int x, int y)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Cur = { x * 2,y };
	SetConsoleCursorPosition(hOut, Cur);
}

void ConsoleCursor(bool _bVis, DWORD _dwSize)
{
	CONSOLE_CURSOR_INFO curinfo;
	curinfo.bVisible = _bVis;
	curinfo.dwSize = _dwSize;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo);
}

void SetColor(int _color, int _bgcolor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		(_bgcolor << 4) | _color);
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