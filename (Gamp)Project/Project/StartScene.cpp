#include<iostream>
#include<conio.h>
#include "StartScene.h"
#include "Console.h"
using namespace std;
int GameMenu()
{
	int x = 30, y = 12;
	Gotoxy(x, y);
	cout << "���� ����";
	Gotoxy(x, y + 1);
	cout << "���� ����";
	Gotoxy(x, y + 2);
	cout << "���� �ϱ�";
	while (true)
	{
		int iKey = KeyController();
		switch (iKey)
		{
		case (int)KEY::UP:
		{
			if (y > 12)
			{
				Gotoxy(x - 2, y);
				cout << " ";
				Gotoxy(x - 2, --y);
				cout << ">";
			}
		}
		break;
		case (int)KEY::DOWN:
		{
			if (y < 14)
			{
				Gotoxy(x - 2, y);
				cout << " ";
				Gotoxy(x - 2, ++y);
				cout << ">";
			}
		}
		break;
		case (int)KEY::SPACE:
		{
			return y - 12;
		}
		break;
		}
	}
}

int KeyController()
{
	int iKey = _getch();
	if (iKey == 224)
	{
		iKey = _getch();

		switch (iKey)
		{
		case 72:
		{
			return (int)KEY::UP;
		}
		break;
		case 80:
			return (int)KEY::DOWN;
			break;
		}
	}
	else if (iKey == 32)
		return (int)KEY::SPACE;
}

void GameInfo()
{
	system("cls");
	cout << endl << endl;
	cout << "[���۹�]" << endl;
	cout << "�޴� �̵�: ����Ű" << endl;
	cout << "�޴� ����: �����̽���" << endl;
	cout << "����Ű�� ������ ī������ ������ ����� �ʵ��� �����ϼ���\n" << endl;
	SetColor((int)COLOR::RED, (int)COLOR::BLACK);
	cout << "��ֹ� ����\n";

	cout << "ŸƮü��:";
	SetColor((int)COLOR::RED, (int)COLOR::BLACK);
	cout << " ��";
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	cout << "  ŸƮü������ ������ ���ϴµ� ������ �ִ� ������ �������� �ſ� ǳ���ϰ� ��� �־� ���鿡 ������ �ش�.\n";
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);

	SetColor((int)COLOR::GREEN, (int)COLOR::BLACK);
	cout << "�ñ�ġ:";
	cout << " ��";
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	cout << "  �ñ�ġ�� ����, ���� �� ��� ��ä�ҿ��� Į���� ǳ���� ���ӿ��� ���� ȣ������ ������ ������ �����Ѵ�.\n";
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);

	SetColor((int)FOREGROUND_RED | FOREGROUND_GREEN, (int)COLOR::BLACK);
	cout << "�Ƹ��:";
	cout << " ��";
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	cout << "  �Ƹ�忡�� ���׳׽��� ǳ���ѵ�, �̴� ������ ���� ����ϰ� ���� ������ �Ӹ� �ƴ϶� ������ �����ϴ� ������ �˷��� ��Ʈ���� ȣ������ �ڸ�Ƽ�� ��ġ�� ���̴� �� ������ �� �� �ִ�.\n\n";

	SetColor((int)COLOR::BLUE, (int)COLOR::BLACK);
	cout << "ī���� ����\n";
	cout << "��*��Ŀ��: ";
	SetColor((int)FOREGROUND_RED | FOREGROUND_GREEN, (int)COLOR::BLUE);
	cout << "*";
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	cout << "  ���������� ������ ���� ���� ������ ĵĿ���Դϴ�\n";


	SetColor((int)COLOR::GREEN, (int)COLOR::BLACK);
	cout << "��*��: ";
	SetColor((int)COLOR::GREEN, (int)FOREGROUND_INTENSITY);
	cout << "m";
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	cout << "  �������帵ũ �� ���� �α� �ִ»�ǰ �Դϴ�. ȿ���� ����մϴ�.\n\n";

	cout << "������ : Space";

	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	
	while (true)
	{
		if (KeyController() == (int)KEY::SPACE)
			break;
	}
}