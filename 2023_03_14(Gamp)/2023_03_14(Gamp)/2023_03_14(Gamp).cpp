#include <iostream>
#include <Windows.h>
using namespace std;

enum MODE
{
	Easy = 1,
	Normal,
	Hard
};

int main()
{
	NumberGame();
}

void NumberGame()
{
	MODE mode;
	int iNansu;
	srand((unsigned int)time(NULL));
	iNansu = rand() % 100;

	cout << "���̵��� �����ϼ���(Easy : 1, Normal : 2, Hard : 3)";
	cin >> mode;

	switch (mode)
	{
	case Easy:
		Sleep(mode * 1000);
		break;
	case Normal:
		Sleep(mode * 1000);
		break;
	case Hard:
		Sleep(mode * 1000);
		break;
	}


	system("cls");

}