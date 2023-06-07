﻿#include<iostream>
#include<io.h>
#include<fcntl.h>
#include<Windows.h>
#include<algorithm>
#include "GameLogic.h"
#include "Console.h"

using namespace std;
void Asciiart()
{
	/*int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"	██████╗  ██████╗ ███╗   ███╗██████╗     ███╗   ███╗ █████╗ ███╗   ██╗ " << endl;
	wcout << L"	██╔══██╗██╔═══██╗████╗ ████║██╔══██╗    ████╗ ████║██╔══██╗████╗  ██║ " << endl;
	wcout << L"	██████╔╝██║   ██║██╔████╔██║██████╔╝    ██╔████╔██║███████║██╔██╗ ██║ " << endl;
	wcout << L"	██╔══██╗██║   ██║██║╚██╔╝██║██╔══██╗    ██║╚██╔╝██║██╔══██║██║╚██╗██║ " << endl;
	wcout << L"	██████╔╝╚██████╔╝██║ ╚═╝ ██║██████╔╝    ██║ ╚═╝ ██║██║  ██║██║ ╚████║ " << endl;
	wcout << L"	╚═════╝  ╚═════╝ ╚═╝     ╚═╝╚═════╝     ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝ " << endl;
	int Curmode = _setmode(_fileno(stdout), prevmode);*/
}

void Init(char _map[VERTICAL][HORIZON], PPLAYER playerPos, PPOS startPos)
{
	//system("mode con cols=80 lines=30");
	// 제목 설정.
	//SetConsoleTitle(TEXT("2-1 Bombman"));
	ConsoleCursor(false, 1);
	startPos->x = 9;
	startPos->y = 10;
	PLAYER setplayer = { *startPos, {} };
	*playerPos = setplayer;

	// string copy.. 0: 벽, 1: 길, 2: 시작지점, 3: 끝지점
	strcpy_s(_map[0], "000000000000000000000000000002");
	strcpy_s(_map[1], "011111111111111111111111111102");
	strcpy_s(_map[2], "011111111111111111111111111102");
	strcpy_s(_map[3], "011111111111111111111111111102");
	strcpy_s(_map[4], "011111111111111111111111111102");
	strcpy_s(_map[5], "011111111111111111111111111102");
	strcpy_s(_map[6], "011111111111111111111111111102");
	strcpy_s(_map[7], "011111111111111111111111111102");
	strcpy_s(_map[8], "011111111111111111111111111102");
	strcpy_s(_map[9], "011111111111111111111111111102");
	strcpy_s(_map[10], "011111111111111111111111111102");
	strcpy_s(_map[11], "011111111111111111111111111102");
	strcpy_s(_map[12], "011111111111111111111111111102");
	strcpy_s(_map[13], "011111111111111111111111111102");
	strcpy_s(_map[14], "011111111111111111111111111102");
	strcpy_s(_map[15], "011111111111111111111111111102");
	strcpy_s(_map[16], "011111111111111111111111111102");
	strcpy_s(_map[17], "011111111111111111111111111102");
	strcpy_s(_map[18], "011111111111111111111111111102");
	strcpy_s(_map[19], "000000000000000000000000000002");
}

void Update(char _map[VERTICAL][HORIZON], PPLAYER _pPlayer)
{
	_pPlayer->newPos = _pPlayer->playerPos;

	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		--_pPlayer->newPos.y;
		Sleep(10);
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		++_pPlayer->newPos.y;
		Sleep(10);
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		--_pPlayer->newPos.x;
		Sleep(10);
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		++_pPlayer->newPos.x;
		Sleep(10);
	}
	// 벽 밖인지 clamp
	_pPlayer->newPos.x = std::clamp(_pPlayer->newPos.x, 0, HORIZON - 2);
	_pPlayer->newPos.y = std::clamp(_pPlayer->newPos.y, 0, VERTICAL - 1);

	if (_map[_pPlayer->newPos.y][_pPlayer->newPos.x] != '0') // 0은 벽.
	{
		_pPlayer->playerPos = _pPlayer->newPos;
	}
	Sleep(100);
}

void Render(char _map[VERTICAL][HORIZON], PPLAYER _player)
{

	for (int i = 0; i < VERTICAL; i++)
	{
		for (int j = 0; j < HORIZON; j++)
		{
			if (_player->playerPos.x == j && _player->playerPos.y == i)
			{
				cout << "●";
			}
			else if (_map[i][j] == (char)MAPTYPE::WALL) { cout << "■"; }
			else if (_map[i][j] == (char)MAPTYPE::ROAD) { cout << " "; }
			else if (_map[i][j] == (char)MAPTYPE::ENDL) { cout << "\n"; }
			//else { cout << "i: " << i << " " << "j: " << j << " "; }
			                                              
		}
	}
}

