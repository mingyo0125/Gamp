#include "GameLogic.h"
#include<iostream>
#include<io.h>
#include<fcntl.h>
#include<Windows.h>
#include "console.h"
using namespace std;
void Asciiart()
{
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
	wcout<< L"	██████╗  ██████╗ ███╗   ███╗██████╗     ███╗   ███╗ █████╗ ███╗   ██╗ " << endl;
	wcout<< L"	██╔══██╗██╔═══██╗████╗ ████║██╔══██╗    ████╗ ████║██╔══██╗████╗  ██║ " << endl;
	wcout<< L"	██████╔╝██║   ██║██╔████╔██║██████╔╝    ██╔████╔██║███████║██╔██╗ ██║ " << endl;
	wcout<< L"	██╔══██╗██║   ██║██║╚██╔╝██║██╔══██╗    ██║╚██╔╝██║██╔══██║██║╚██╗██║ " << endl;
	wcout<< L"	██████╔╝╚██████╔╝██║ ╚═╝ ██║██████╔╝    ██║ ╚═╝ ██║██║  ██║██║ ╚████║ " << endl;
	wcout << L"	╚═════╝  ╚═════╝ ╚═╝     ╚═╝╚═════╝     ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝ " << endl;
	int Curmode = _setmode(_fileno(stdout), prevmode);


}

void Init(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer, PPOS _pStartpos, PPOS _pEndpos)
{
	system("mode con cols=80 lines=30");
	// 제목 설정.
	SetConsoleTitle(TEXT("2-1 Bombman"));
	ConsoleCursor(false, 1);
	_pStartpos->x = 0;
	_pStartpos->y = 0;
	_pEndpos->x = 19;
	_pEndpos->y = 13;
	PLAYER tSetplayer = { *_pStartpos, 1, 0, false, false, false};
	*_pPlayer = tSetplayer;
	// string copy.. 0: 벽, 1: 길, 2: 시작지점, 3: 끝지점
	strcpy_s(_cMaze[0],	"21100000000000000000");
	strcpy_s(_cMaze[1],	"10111111111000000000");
	strcpy_s(_cMaze[2],	"00100000001111100000");
	strcpy_s(_cMaze[3],	"00100000000000100000");
	strcpy_s(_cMaze[4],	"00100000000000100000");
	strcpy_s(_cMaze[5],	"00100000000000100000");
	strcpy_s(_cMaze[6],	"00100000000000100000");
	strcpy_s(_cMaze[7],	"00100000000000100000");
	strcpy_s(_cMaze[8],	"00111111111000100000");
	strcpy_s(_cMaze[9],	"00000000001000100000");
	strcpy_s(_cMaze[10],"00111111111000100000");
	strcpy_s(_cMaze[11],"00100000000000100000");
	strcpy_s(_cMaze[12],"00111111111111100000");
	strcpy_s(_cMaze[13],"00001000000000001113");
	strcpy_s(_cMaze[14],"00001000000000001000");
	strcpy_s(_cMaze[15],"00001000000000001000");
	strcpy_s(_cMaze[16],"00001111111111111000");
	strcpy_s(_cMaze[17],"00001000000000000000");
	strcpy_s(_cMaze[18],"00001000000000000000");
	strcpy_s(_cMaze[19],"00000000000000000000");
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
	Sleep(100);
}

void Render(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer)
{
	for (int i = 0; i< VERTICAL; i++)
	{
		for (int j = 0; j < HORIZON; j++)
		{
			if (_pPlayer->tPos.x == j && _pPlayer->tPos.y == i)
				cout << "§";
			else if (_cMaze[i][j] == '0')
				cout << "■";
			else if (_cMaze[i][j] == '1')
				cout << " "; // 윈도우11 한칸S
			else if (_cMaze[i][j] == '2')
				cout << "®";
			else if (_cMaze[i][j] == '3')
				cout << "♨";
		}
		cout << endl;
	}
}
