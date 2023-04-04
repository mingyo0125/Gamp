#pragma once
#include<Windows.h>
void FullScreen();
void Gotoxy(int x, int y);
void ConsoleCursor(bool, DWORD);
void SetColor(int, int);
enum class COLOR
{
	BLACK, BLUE, GREEN, SKYBLUE, RED,
	VOILET, YELLOW, LIGHT_GRAY, GRAY,
	LIGHT_BLUE,
	LIGHT_GREEN, MINT, LIGHT_RED,
	LIGHT_VIOLET, LIGHT_YELLOW, WHITE
};