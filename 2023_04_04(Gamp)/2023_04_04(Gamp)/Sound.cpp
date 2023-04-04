#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <mmsystem.h>
#include "resource.h"
#pragma comment(lib, "winmm.lib")
using namespace std;

void Sound()
{
	while (true)
	{
		cout << "절대 음감 게임" << endl << "\n";
		float arr[8] = { 523.25, 587.33, 659.26, 698.46, 783.99, 880, 987.77, 1046.50 };

		Sleep(500);

		for (int i = 0; i < 8; i++)
		{
			Beep(arr[i], 500);
		}

		srand((unsigned int)time(NULL));
		int iRand = rand() % 8 + 1;

		for (int i = 0; i < 3; i++)
		{
			cout << "\r" << 3 - i << "...";
			Sleep(1000);
		}

		system("cls");

		Beep(arr[iRand], 500);

		int input = _getch();

		if (input == iRand)
		{
			cout << "정답입니다" << endl;
		}
		else
		{
			cout << "틀렸습니다." << endl;
		}
		cout << "다시하시겠습니까? (Y / N)" << endl;

		char con;
		cin >> con;

		if (con == 'Y')
		{
			system("cls");
			continue;
		}
		else
		{
			break;
		}
	}
	
}

int main()
{
	//PlaySound(TEXT("explosion.wav"), NULL, SND_FILENAME);
	PlaySound(MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_RESOURCE);
	Sound();
}