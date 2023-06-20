#pragma once
#include <Windows.h>

enum class COLOR
{
	BLACK, BLUE, GREEN, SKYBLUE, RED,
	VOILET, YELLOW, LIGHT_GRAY, GRAY, LIGHT_BLUE,
	LIGHT_GREEN, MINT, LIGHT_RED, LIGHT_VIOLET, LIGHT_YELLOW, WHITE
};

void Gotoxy(int, int);
void Gotoxyplayer(int, int);
void ConsoleCursor(bool, DWORD);
void SetColor(int, int);