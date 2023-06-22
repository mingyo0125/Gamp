#include<iostream>
#include<io.h>
#include<fcntl.h>
#include<Windows.h>
#include<algorithm>
#include <ctime>
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
	strcpy_s(_map[0], "000000000000000000000000000002"); //30
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

	MakeItem((char)MAPTYPE::CAFFEINE, _map);
}

void Update(char _map[VERTICAL][HORIZON], PPLAYER playerPos, float&hpCnt, bool &isGameOver)
{
	playerPos->newPos = playerPos->playerPos;

	hpCnt -= 1;

	if (hpCnt <= 0)
	{
		GameOver(isGameOver);
		return;
	}

#pragma region  Move
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			--playerPos->newPos.y;
			Sleep(10);
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			++playerPos->newPos.y;
			Sleep(10);
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			--playerPos->newPos.x;
			Sleep(10);
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			++playerPos->newPos.x;
			Sleep(10);
		}

		playerPos->newPos.x = std::clamp(playerPos->newPos.x, 0, HORIZON - 2);
		playerPos->newPos.y = std::clamp(playerPos->newPos.y, 0, VERTICAL - 1);

		if (_map[playerPos->newPos.y][playerPos->newPos.x] != (char)MAPTYPE::WALL)
		{
			playerPos->playerPos = playerPos->newPos;
		}

		Sleep(100);
	

#pragma endregion

	MakeItem((char)MAPTYPE::OBSTACLE, _map);

	if (_map[playerPos->newPos.y][playerPos->newPos.x] == (char)MAPTYPE::CAFFEINE)
	{
		GetItme((char)MAPTYPE::CAFFEINE, playerPos, hpCnt);
		_map[playerPos->newPos.y][playerPos->newPos.x] = (char)MAPTYPE::ROAD;
		MakeItem((char)MAPTYPE::CAFFEINE, _map);
	}
	else if (_map[playerPos->playerPos.y][playerPos->playerPos.x] == (char)MAPTYPE::OBSTACLE)
	{
		_map[playerPos->newPos.y][playerPos->newPos.x] = (char)MAPTYPE::ROAD;
		GetItme((char)MAPTYPE::OBSTACLE, playerPos, hpCnt);
		MakeItem((char)MAPTYPE::OBSTACLE, _map);
	}
}

void Render(char _map[VERTICAL][HORIZON], PPLAYER _player, float&hpCnt)
{
	const string cellSpacing = " ";
	cout << cellSpacing;
	cout << cellSpacing;

	for (int i = 0; i < VERTICAL; i++)
	{
		for (int j = 0; j < HORIZON; j++)
		{
			if (_player->playerPos.x == j && _player->playerPos.y == i)
			{
				cout << "●";
			}
			else if (_map[i][j] == (char)MAPTYPE::OBSTACLE) { cout << "#"; }
			else if (_map[i][j] == (char)MAPTYPE::CAFFEINE)
			{
				SetColor((int)FOREGROUND_RED | FOREGROUND_GREEN, (int)COLOR::BLUE);
				cout << "*";
				SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
			}
			else if (_map[i][j] == (char)MAPTYPE::WALL) { cout << "■"; }
			else if (_map[i][j] == (char)MAPTYPE::ROAD) { cout << " "; }
			else if (_map[i][j] == (char)MAPTYPE::ENDL) { cout << "\n"; }
			
			
			cout << cellSpacing;
		}
	}

	cout << "\n";
	cout << "\n";

	for (int i = 0; i < 15; i++)
	{
		cout << cellSpacing;;
	}

	for (int i = 0; i < 31; i++)
	{
		if (i <= hpCnt) { cout << "■"; }
		else { cout << " "; }
	}
}

void GetItme(char item, PPLAYER _playerPos, float &hpCnt)
{
	if (item == (char)MAPTYPE::CAFFEINE)
	{
		hpCnt += 17;
		//사운드 재생
	}
	else if (item == (char)MAPTYPE::OBSTACLE)
	{
		hpCnt -= 5;
		//사운드재생
	}
}

void MakeItem(char item, char _map[VERTICAL][HORIZON])
{
	srand((unsigned int)time(NULL));

	int verRand, horiRand;

	verRand = rand() % VERTICAL;
	horiRand = rand() % HORIZON;

	verRand = std::clamp(verRand, 1, 27);
	horiRand = std::clamp(horiRand, 1, 17);

	if (item == (char)MAPTYPE::CAFFEINE)
	{
		_map[horiRand][verRand] = item;
	}
	else
	{
		_map[horiRand + 1][verRand + 1] = item;

	}

}

void GameOver(bool &isGameOver)
{
	isGameOver = true;
}
 


