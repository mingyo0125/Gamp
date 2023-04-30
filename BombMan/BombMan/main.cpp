#include<iostream>
#include "Console.h"
#include "GameLogic.h"
#include "StartScene.h"
using namespace std;
int main()
{
	// �� 20 X 20
	char cMaze[VERTICAL][HORIZON] = {};
	PLAYER tPlayer = {};
	POS tStartpos = {};
	POS tEndpos = {};
	Init(cMaze, &tPlayer, &tStartpos, &tEndpos);
	// �ƽ�Ű��Ʈ.
	while (true)
	{
		system("cls");
		Asciiart();
		int iMenu = GameMenu();
		if (iMenu == 0) // ���� ����
			break;
		else if (iMenu == 1) // ���� ����
			GameInfo();
		else if (iMenu == 2) // �����ϱ�
		{
			cout << "������ �����մϴ�." << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << '\r' << 3 - i << "...";
				Sleep(1000);
			}
			return 0;
		}
	}
	// ���� ����.. 
	while (true)
	{
		//		system("cls");
		Gotoxy(0, 0);
		Update(cMaze, &tPlayer);
		Render(cMaze, &tPlayer);
	}
}