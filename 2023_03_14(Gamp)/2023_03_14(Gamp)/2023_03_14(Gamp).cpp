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

	cout << "���̵��� �����ϼ���(Easy : 1, Normal : 2, Hard : 3) : ";
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
				cout << "Ʋ�Ƚ��ϴ�";
				break;
			}
		}

		if (inputAns[4] == Nansu[4])
		{
			cout << "�����Դϴ�";
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
				cout << "Ʋ�Ƚ��ϴ�";
				break;
			}
		}

		if (inputAns[4] == Nansu[4])
		{
			cout << "�����Դϴ�";
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
				cout << "Ʋ�Ƚ��ϴ�";
				break;
			}
		}

		if (inputAns[4] == Nansu[4])
		{
			cout << "�����Դϴ�";
		}
		break;

	default:
		cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���";
	}


}

int main()
{
	NumberGame();
}
