#include<iostream>
#include<vector> // erase, iter.
#include<Windows.h>
#include<mmsystem.h>
#include "console.h"
#include "GameLogic.h"
#include "StartScene.h"
#pragma comment(lib, "winmm.lib")

using namespace std;
int main()
{

	// �� 20 X 20
	char cMaze[VERTICAL][HORIZON] = {};
	PLAYER tPlayer = {};
	POS tStartpos = {};
	POS tEndpos = {};
	vector<BOOM> vecBomb;
	vector<POS> boomEffect;
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
	system("cls");
	clock_t oldtime, curtime;
	oldtime = clock();
	while (true)
	{
		//		system("cls");
		Gotoxy(0, 0);
		Update(cMaze, &tPlayer, vecBomb, boomEffect);
		Render(cMaze, &tPlayer, boomEffect);
		Event(vecBomb, boomEffect);
		if (tPlayer.tPos.x == tEndpos.x &&
			tPlayer.tPos.y == tEndpos.y)
		{
			PlaySound(TEXT("endsound.wav"), 0, SND_FILENAME | SND_ASYNC);
			Sleep(1000);
			break;
		}
		while (true)
		{
			curtime = clock();
			if (curtime - oldtime >= 1000)
			{
				oldtime = curtime;
				break;
			}
		}
	}
}