#include"GameLogic.h"
#include<iostream>
#include <io.h>
#include <fcntl.h>
#include"console.h"
using namespace std;
void Asciiart()
{
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"	██████╗  ██████╗ ███╗   ███╗██████╗     ███╗   ███╗ █████╗ ███╗   ██╗ " << endl;
	wcout << L"	██╔══██╗██╔═══██╗████╗ ████║██╔══██╗    ████╗ ████║██╔══██╗████╗  ██║ " << endl;
	wcout << L"	██████╔╝██║   ██║██╔████╔██║██████╔╝    ██╔████╔██║███████║██╔██╗ ██║ " << endl;
	wcout << L"	██╔══██╗██║   ██║██║╚██╔╝██║██╔══██╗    ██║╚██╔╝██║██╔══██║██║╚██╗██║ " << endl;
	wcout << L"	██████╔╝╚██████╔╝██║ ╚═╝ ██║██████╔╝    ██║ ╚═╝ ██║██║  ██║██║ ╚████║ " << endl;
	wcout << L"	╚═════╝  ╚═════╝ ╚═╝     ╚═╝╚═════╝     ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝ " << endl;
	int Curmode = _setmode(_fileno(stdout), prevmode);
	
}
void Init(char _cMaze[VERTICAL][HORIZON], PPLAYER
	_pPlayer, PPOS _pStartpos, PPOS _pEndpos) {
	system("mode con cols=80 lines = 30");
	// 제목 설정
	SetConsoleTitle(TEXT("2-1 Bombman"));
	ConsoleCursor(false, 1);
	_pStartpos->x = 0;
	_pStartpos->y = 0;
	_pEndpos->y = 19;
	_pEndpos->y = 13;
	PLAYER tSetplayer = { *_pStartpos, 1, 0, false, false, false };
	*_pPlayer = tSetplayer;

	strcpy_s(_cMaze[0],  "21100000000000000111");
	strcpy_s(_cMaze[1],  "00100000000000000111");
	strcpy_s(_cMaze[2],  "00100000000000000111");
	strcpy_s(_cMaze[3],  "00100000000000000111");
	strcpy_s(_cMaze[4],  "00100000000000000111");
	strcpy_s(_cMaze[5],  "00111111111110000111");
	strcpy_s(_cMaze[6],  "00000000000010000111");
	strcpy_s(_cMaze[7],  "00000000000010000111");
	strcpy_s(_cMaze[8],  "00000000000010000111");
	strcpy_s(_cMaze[9],  "00000000000010000111");
	strcpy_s(_cMaze[10], "00000000000010000111");
	strcpy_s(_cMaze[11], "00000000000010000111");
	strcpy_s(_cMaze[12], "00000000000010000111");
	strcpy_s(_cMaze[13], "01111111111111000111");
	strcpy_s(_cMaze[14], "00000000000000000111");
	strcpy_s(_cMaze[15], "00000000000000000111");
	strcpy_s(_cMaze[16], "00000000000000000111");
	strcpy_s(_cMaze[17], "00000000000000000111");
	strcpy_s(_cMaze[18], "00000000000000000111");
	strcpy_s(_cMaze[19], "01111111111111111111");
}

void Update(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer)
{
	// GetAsyncKeyState
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		--_pPlayer->tPos.y;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		++_pPlayer->tPos.y;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		--_pPlayer->tPos.x;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		++_pPlayer->tPos.x;
	Sleep(40);
}
void Render(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer)
{
	for (int i = 0; i < VERTICAL; i++)
	{
		for (int j = 0; j < HORIZON; j++)
		{
			if (_pPlayer->tPos.x == j && _pPlayer->tPos.y == i)
				cout << "∮";
			else if (_cMaze[i][j] == (char)MAPTYPE::WALL)
				cout << "■";
			else if (_cMaze[i][j] == (char)MAPTYPE::ROAD)
				cout << "  ";
			else if (_cMaze[i][j] == (char)MAPTYPE::START)
				cout << "®";
			else if (_cMaze[i][j] == (char)MAPTYPE::END)
				cout << "♨";
		}
		cout << endl;	
	}
}