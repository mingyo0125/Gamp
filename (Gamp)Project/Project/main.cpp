#include <iostream>
#include "Console.h"
#include "GameLogic.h"
#include "StartScene.h"

using namespace std;;
int main()
{
	char map[VERTICAL][HORIZON] = {};
	PLAYER player = {};
	POS startpos = {};
	Init(map, &player, &startpos);
	int hpCnt = 31;
	bool isGameOver = false;

	while (true)
	{
		Gotoxy(0, 0);

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
	
	system("cls");

	while (true)
	{
		Gotoxy(0, 0);
		Render(map, &player, hpCnt);
		Update(map, &player, hpCnt, isGameOver);

		if (isGameOver)
		{
			system("cls");
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < i; j++)
				{
					cout << "Z" << "...";
					Sleep(500);
				}
			}
			return 0;
		}
	}
}
