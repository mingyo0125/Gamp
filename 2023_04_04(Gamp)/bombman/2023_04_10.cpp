#include <iostream>
#include "console.h"
#include "GameLogic.h"
#include "StartScene.h"

using namespace std;
int main()
{
	while (true)
	{
		Asciiart();
		int menu = GameMenu();
		if (menu == 0) //게임 시작
		{

		}
		else if (menu == 1) //게임 정보
		{
			GameInfo();
		}
		else if (menu == 2) //종료
		{
			cout << "게임을 종료합니다" << "\n";
			for (int i = 0; i < 3; i++)
			{
				cout << "\r" << 3 - i << "...";
				Sleep(1000);
			}
			return 0;
		}
	}
}