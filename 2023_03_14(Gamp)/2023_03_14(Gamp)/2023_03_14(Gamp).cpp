#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

enum MODE
{
	Easy = 1,
	Normal,
	Hard
};

void NumberGame()
{
	int Nansu[5];
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 5; i++)
	{
		Nansu[i] = rand() % 100;
	}

	cout << "난이도를 선택하세요(Easy : 1, Normal : 2, Hard : 3) : ";
	int difficulty;
	cin >> difficulty;
	int inputAns[5];

	switch (difficulty)
	{
	case Easy:
		for (int i = 0; i < 5; i++)
		{
			cout << Nansu[i] << " ";
			Sleep(1000);
		}
		system("cls");
		for (int j = 0; j < 5; j++)
		{
			cin >> inputAns[j];
			if (inputAns[j] != Nansu[j])
			{
				cout << "틀렸습니다";
				break;
			}
		}

		if (inputAns[4] == Nansu[4])
		{
			cout << "정답입니다";
		}
		break;

	case Normal:
		for (int i = 0; i < 5; i++)
		{
			cout << Nansu[i] << " ";
			Sleep(700);
		}
		system("cls");
		for (int j = 0; j < 5; j++)
		{
			cin >> inputAns[j];
			if (inputAns[j] != Nansu[j])
			{
				cout << "틀렸습니다";
				break;
			}
		}

		if (inputAns[4] == Nansu[4])
		{
			cout << "정답입니다";
		}
		break;

	case Hard:
		for (int i = 0; i < 5; i++)
		{
			cout << Nansu[i] << " ";
			Sleep(500);
		}
		system("cls");
		for (int j = 0; j < 5; j++)
		{
			cin >> inputAns[j];
			if (inputAns[j] != Nansu[j])
			{
				cout << "틀렸습니다";
				break;
			}
		}

		if (inputAns[4] == Nansu[4])
		{
			cout << "정답입니다";
		}
		break;

	default:
		cout << "잘못 입력하셨습니다. 다시 입력해주세요";
	}


}

int main()
{
	NumberGame();
}
