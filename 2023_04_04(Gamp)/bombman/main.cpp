#include <iostream>
#include "console.h"
using namespace std;

int main()
{
	//system("calc");
	//system("notepad");
	//system("mode con cols=50 lines=50 | title �츶��");
	//SetConsoleTitle(TEXT("�����ֿ� �����ֿ� �����ֿ� ������"));
	//FullScreen();
	//system("pause");
	//exit(0);
	
	cout << "������";
	Gotoxy(10, 10);
	ConsoleCursor(false, 1);
	SetColor((int)COLOR::MINT, (int)COLOR::SKYBLUE);
	cout << "������";

	int a;
	cin >> a;
}	