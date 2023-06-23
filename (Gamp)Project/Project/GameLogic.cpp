#include<iostream>
#include<io.h>
#include<fcntl.h>
#include<Windows.h>
#include <mmsystem.h>
#include<algorithm>
#include <ctime>
#include "GameLogic.h"
#include "Console.h"

#pragma comment(lib, "winmm.lib")

using namespace std;
void Asciiart()
{
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);


	wcout << L" ██████╗  ██╗██╗   ██╗███████╗   ██████╗ █████╗ ███████╗███████╗███████╗██╗███╗   ██╗███████╗	" << endl;
	wcout << L" ██╔════╝ ██║██║   ██║██╔════╝  ██╔════╝██╔══██╗██╔════╝██╔════╝██╔════╝██║████╗  ██║██╔════╝	" << endl;
	wcout << L" ██║  ███╗██║██║   ██║█████╗    ██║     ███████║█████╗  █████╗  █████╗  ██║██╔██╗ ██║█████╗  	" << endl;
	wcout << L" ██║   ██║██║╚██╗ ██╔╝██╔══╝    ██║     ██╔══██║██╔══╝  ██╔══╝  ██╔══╝  ██║██║╚██╗██║██╔══╝  	" << endl;
	wcout << L" ╚██████╔╝██║ ╚████╔╝ ███████╗  ╚██████╗██║  ██║██║     ██║     ███████╗██║██║ ╚████║███████╗	" << endl;
	wcout << L" ╚═════╝ ╚═╝  ╚═══╝  ╚══════╝   ╚═════╝╚═╝  ╚═╝╚═╝     ╚═╝     ╚══════╝╚═╝╚═╝  ╚═══╝╚══════╝ 	" << endl;


	int Curmode = _setmode(_fileno(stdout), prevmode);
}

void Init(char _map[VERTICAL][HORIZON], PPLAYER playerPos, PPOS startPos)
{
	//system("mode con cols=80 lines=30");
	// 제목 설정.
	//SetConsoleTitle(TEXT("If you don't eat CAFFEINE soon, you'll Sleep!"));
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

	MakeItem((char)MAPTYPE::COFFEE, _map);
}

void Update(char _map[VERTICAL][HORIZON], PPLAYER playerPos, int &hpCnt, bool &isGameOver)
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

	//랜덤처리
	srand((unsigned int)time(NULL));
	int ObrandNum = rand() % 4;

	switch (ObrandNum)
	{
	case 1:
		MakeItem((char)MAPTYPE::CHERRY, _map);
		break;
	case 2:
		MakeItem((char)MAPTYPE::SPINACH, _map);
		break;
	case 3:
		MakeItem((char)MAPTYPE::ALMOND, _map);
		break;
	}

	int randNum = rand() % 30;
	if (randNum == 1)
	{
		MakeItem((char)MAPTYPE::MONSTER, _map);
	}

	if (_map[playerPos->newPos.y][playerPos->newPos.x] == (char)MAPTYPE::COFFEE)
	{
		GetItme((char)MAPTYPE::COFFEE, playerPos, hpCnt);
		_map[playerPos->newPos.y][playerPos->newPos.x] = (char)MAPTYPE::ROAD;
		MakeItem((char)MAPTYPE::COFFEE, _map);
	}
	else if (_map[playerPos->newPos.y][playerPos->newPos.x] == (char)MAPTYPE::MONSTER)
	{
		GetItme((char)MAPTYPE::MONSTER, playerPos, hpCnt);
		_map[playerPos->newPos.y][playerPos->newPos.x] = (char)MAPTYPE::ROAD;
		MakeItem((char)MAPTYPE::MONSTER, _map);
	}
	else if (_map[playerPos->playerPos.y][playerPos->playerPos.x] == (char)MAPTYPE::CHERRY)
	{
		_map[playerPos->newPos.y][playerPos->newPos.x] = (char)MAPTYPE::ROAD;
		GetItme((char)MAPTYPE::CHERRY, playerPos, hpCnt);
		MakeItem((char)MAPTYPE::CHERRY, _map);
	}
	else if (_map[playerPos->playerPos.y][playerPos->playerPos.x] == (char)MAPTYPE::SPINACH)
	{
		_map[playerPos->newPos.y][playerPos->newPos.x] = (char)MAPTYPE::ROAD;
		GetItme((char)MAPTYPE::SPINACH, playerPos, hpCnt);
		MakeItem((char)MAPTYPE::SPINACH, _map);
	}
	else if (_map[playerPos->playerPos.y][playerPos->playerPos.x] == (char)MAPTYPE::ALMOND)
	{
		_map[playerPos->newPos.y][playerPos->newPos.x] = (char)MAPTYPE::ROAD;
		GetItme((char)MAPTYPE::ALMOND, playerPos, hpCnt);
		MakeItem((char)MAPTYPE::ALMOND, _map);
	}

}

void Render(char _map[VERTICAL][HORIZON], PPLAYER _player, int &hpCnt)
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
			else if(_map[i][j] == (char)MAPTYPE::CHERRY)
			{
				SetColor((int)COLOR::RED, (int)COLOR::BLACK);
				cout << "●";
				SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
			}
			else if (_map[i][j] == (char)MAPTYPE::SPINACH)
			{
				SetColor((int)COLOR::GREEN, (int)COLOR::BLACK);
				cout << "♣";
				SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
			}
			else if (_map[i][j] == (char)MAPTYPE::ALMOND)
			{
				SetColor((int)FOREGROUND_RED | FOREGROUND_GREEN, (int)COLOR::BLACK);
				cout << "β";
				SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
			}
			else if (_map[i][j] == (char)MAPTYPE::COFFEE)
			{
				SetColor((int)FOREGROUND_RED | FOREGROUND_GREEN, (int)COLOR::BLUE);
				cout << "*";
				SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
			}
			else if (_map[i][j] == (char)MAPTYPE::MONSTER)
			{
				SetColor((int)COLOR::GREEN, (int)FOREGROUND_INTENSITY);
				cout << "m";
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

void GetItme(char item, PPLAYER _playerPos, int &hpCnt)
{
	if (item == (char)MAPTYPE::COFFEE)
	{
		hpCnt += 15;
		hpCnt = std::clamp(hpCnt, 0, 31);
		PlaySound(TEXT("545238__mr_fritz__item-sparkle"), 0, SND_FILENAME | SND_ASYNC);
		//사운드 재생
	}
	else if(item == (char)MAPTYPE::MONSTER)
	{
		PlaySound(TEXT("545238__mr_fritz__item-sparkle"), 0, SND_FILENAME | SND_ASYNC);
		hpCnt += 30;
		//사운드 재생
	}
	else if (item == (char)MAPTYPE::CHERRY)
	{
		PlaySound(TEXT("690623__guinamun__item-wag"), 0, SND_FILENAME | SND_ASYNC);
		hpCnt -= 3;
		//사운드재생
	}
	else if (item == (char)MAPTYPE::SPINACH)
	{
		PlaySound(TEXT("690623__guinamun__item-wag"), 0, SND_FILENAME | SND_ASYNC);
		hpCnt -= 5;
		//사운드재생
	}
	else if (item == (char)MAPTYPE::ALMOND)
	{
		PlaySound(TEXT("690623__guinamun__item-wag"), 0, SND_FILENAME | SND_ASYNC);
		hpCnt -= 7;
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

	if (item == (char)MAPTYPE::COFFEE)
	{
		_map[horiRand][verRand] = item;
	}
	else if(item == (char)MAPTYPE::MONSTER)
	{
		_map[10][14] = item;
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
 


