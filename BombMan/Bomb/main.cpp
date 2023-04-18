#include<iostream>
#include<vector>
#include<Windows.h>
#include<mmsystem.h>
#include "console.h"
#include "GameLogic.h"
#include "StartScene.h"
using namespace std;
int main()
{
	// 맵 20 X 20
	char cMaze[VERTICAL][HORIZON] = {};
	PLAYER tPlayer = {};
	POS tStartpos = {};
	POS tEndpos = {};
	vector<BOOM> vecBomb;
	vector<POS> boomEffect;
	Init(cMaze, &tPlayer, &tStartpos, &tEndpos);
	system("mode con cols=80 lines=30");
	// 아스키아트.
	while (true)
	{
		system("cls");
		Asciiart();
		int iMenu = GameMenu();
		if (iMenu == 0) // 게임 시작
			break;
		else if (iMenu == 1) // 게임 정보
			GameInfo();
		else if (iMenu == 2) // 종료하기
		{
			cout << "게임을 종료합니다." << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << '\r' << 3 - i << "...";
				Sleep(1000);
			}
			return 0;
		}
	}
	// 게임 로직.. 
	while (true) {
		//system("cls");
		Gotoxy(0, 0);
		Update(cMaze, &tPlayer, vecBomb, boomEffect);
		Render(cMaze, &tPlayer, boomEffect);

		if (tPlayer.tPos.x == tEndpos.x &&
			tPlayer.tPos.y == tEndpos.y)
		{
			PlaySound(TEXT("random.wav"), 0, SND_FILENAME | SND_ASYNC);
			Sleep(1000);
			break;
		}
	}
}