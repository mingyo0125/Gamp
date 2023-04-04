#include <iostream>
#include "console.h"
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
	
	cout << "유형주";
	Gotoxy(10, 10);
	ConsoleCursor(false, 1);
	SetColor((int)COLOR::MINT, (int)COLOR::SKYBLUE);
	cout << "안형주";

	int a;
	cin >> a;
}	