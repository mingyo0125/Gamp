#include <iostream>
#include "console.h"
#include <time.h>
#include <conio.h>;
using namespace std;

int main()
{
	//system("calc");
	//system("notepad");
	//system("mode con cols=50 lines=50 | title 우마이");
	//SetConsoleTitle(TEXT("안형주와 유형주와 김형주와 제형주"));
	//FullScreen();
	//system("pause");
	//exit(0);
	
	/*cout << "유형주";
	Gotoxy(10, 10);
	ConsoleCursor(false, 1);
	SetColor((int)COLOR::MINT, (int)COLOR::SKYBLUE);
	cout << "안형주";*/

#pragma region Color

	/*
	Gotoxy(10, 10);
	cout << "Hello World";
	Sleep(3000);
	int oldColor = GetColor() | (GetbgColor() << 4);
	system("cls");
	for (int i = 0; i <= 15; i++)
	{
		Gotoxy(i, i);
		SetColor(i, (int)COLOR :: BLACK);
		cout << "color number: ";
		//SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
		SetColor(oldColor, oldColor >> 4);
		cout << i << "\n";
	}
	*/

#pragma endregion
	int test;
	int x = 0, y = 0;
	int beforex = 0, beforey = 0;
	HWND hConsole = GetConsoleWindow();
	SetWindowLong(hConsole, GWL_STYLE, GetWindowLong(hConsole, GWL_STYLE) & ~WS_SIZEBOX);
	RECT rt;
	GetWindowRect(hConsole, &rt);
	clock_t Oldtime, Curtime;
	Oldtime = clock();

	while (true)
	{
		Curtime = clock();
		if (Curtime - Oldtime > 1000)
		{
			cout << "1초가 지났다." << "\n";
			Oldtime = Curtime;
		}
		//if (_kbhit())
		//{
		//	test = _getch();
		//	if (test == 224)
		//	{
		//		test = _getch();
		//		switch (test)
		//		{
		//		case 72:
		//			//cout << "위쪽" << "\n";
		//			y--;
		//			break;
		//		case 75:
		//			//cout << "왼쪽" << "\n";
		//			x--;
		//			break;
		//		case 77:
		//			//cout << "오른쪽" << "\n";
		//			x++;
		//			break;
		//		case 80:
		//			//cout << "아래쪽" << "\n";
		//			y++;
		//			break;
		//		}
		//	}
		//}

#pragma region 키보드 입력
		BOOL result = GotoxyBOOL(x, y);
		if (result == FALSE)
		{
			x = beforex;
			y = beforey;
			continue;
		}
		else
		{
			beforex = x;
			beforey = y;
		}
		//Gotoxy(x, y);
		
		_putch('a');
		if (GetAsyncKeyState(VK_UP) & 0x8000) y--;
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) y++;
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) x--;
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) x++;
		Sleep(50);
		
#pragma endregion

		/*
		int a;
		while (true)
		{
			cin >> a;
			if (cin.fail())
			{
				cout << "비정상 입력" << "\n";
				cin.clear();
				cin.ignore(1024, '\n');
			}
		}
		*/

		
	}
}	