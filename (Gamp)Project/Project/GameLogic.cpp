#include<iostream>
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


	MakeItem((char)MAPTYPE::Caffeine, _map);

}

void Update(char _map[VERTICAL][HORIZON], PPLAYER playerPos)
{
	playerPos->newPos = playerPos->playerPos;

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

	if (_map[playerPos->newPos.y][playerPos->newPos.x] == (char)MAPTYPE::Caffeine)
	{
		GetItme((char)MAPTYPE::Caffeine, playerPos);
		_map[playerPos->newPos.y][playerPos->newPos.x] = (char)MAPTYPE::ROAD;
		MakeItem((char)MAPTYPE::Caffeine, _map);
	}
}

void Render(char _map[VERTICAL][HORIZON], PPLAYER _player)
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
			else if (_map[i][j] == (char)MAPTYPE::Caffeine) { cout << "*"; }
			else if (_map[i][j] == (char)MAPTYPE::WALL) { cout << "■"; }
			else if (_map[i][j] == (char)MAPTYPE::ROAD) { cout << " "; }
			else if (_map[i][j] == (char)MAPTYPE::ENDL) { cout << "\n"; }
			/*else if (_map[i][j] == (char)MAPTYPE::WALL) { cout << (char)MAPTYPE::WALL; }
			else if (_map[i][j] == (char)MAPTYPE::ROAD) { cout << (char)MAPTYPE::ROAD; }
			else if (_map[i][j] == (char)MAPTYPE::Caffeine) { cout << (char)MAPTYPE::Caffeine; }
			else if (_map[i][j] == (char)MAPTYPE::ENDL) { cout << "\n"; }*/
			//else { cout << "i: " << i << " " << "j: " << j << " "; }
			
			cout << cellSpacing;
		}
	}
}

void GetItme(char item, PPLAYER _playerPos)
{
	if (item == (char)MAPTYPE::Caffeine)
	{
		//사운드 재생
	}
}

void MakeItem(char item, char _map[VERTICAL][HORIZON])
{
	srand((unsigned int)time(NULL));

	int verRand, horiRand;
	verRand = rand() % VERTICAL;
	horiRand = rand() % HORIZON;

	verRand = std::clamp(verRand, 1, 28);
	horiRand = std::clamp(horiRand, 1, 18);

	_map[horiRand][verRand] = item;
}
 


