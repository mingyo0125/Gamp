#include<iostream>
#include<conio.h>
#include "StartScene.h"
#include "Console.h"
using namespace std;
int GameMenu()
{
	int x = 30, y = 12;
	Gotoxy(x, y);
	cout << "게임 시작";
	Gotoxy(x, y + 1);
	cout << "게임 정보";
	Gotoxy(x, y + 2);
	cout << "종료 하기";
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
	cout << "[조작법]" << endl;
	cout << "메뉴 이동: 방향키" << endl;
	cout << "메뉴 선택: 스페이스바" << endl;
	cout << "방향키를 움직여 카페인을 먹으며 잠들지 않도록 유지하세요\n" << endl;
	SetColor((int)COLOR::RED, (int)COLOR::BLACK);
	cout << "장애물 종류\n";

	cout << "타트체리:";
	SetColor((int)COLOR::RED, (int)COLOR::BLACK);
	cout << " ●";
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	cout << "  타트체리에는 숙면을 취하는데 도움을 주는 성분이 멜라토닌이 매우 풍부하게 들어 있어 숙면에 도움을 준다.\n";
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);

	SetColor((int)COLOR::GREEN, (int)COLOR::BLACK);
	cout << "시금치:";
	cout << " ♣";
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	cout << "  시금치와 케일, 상추 등 녹색 잎채소에는 칼슘이 풍부해 몸속에서 수면 호르몬인 멜라토닌 생성을 촉진한다.\n";
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);

	SetColor((int)FOREGROUND_RED | FOREGROUND_GREEN, (int)COLOR::BLACK);
	cout << "아몬드:";
	cout << " β";
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	cout << "  아몬드에는 마그네슘이 풍부한데, 이는 수면의 질을 향상하고 잠을 촉진할 뿐만 아니라 수면을 방해하는 것으로 알려진 스트레스 호르몬인 코르티솔 수치를 줄이는 데 도움이 될 수 있다.\n\n";

	SetColor((int)COLOR::BLUE, (int)COLOR::BLACK);
	cout << "카페인 종류\n";
	cout << "레*비커피: ";
	SetColor((int)FOREGROUND_RED | FOREGROUND_GREEN, (int)COLOR::BLUE);
	cout << "*";
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	cout << "  편의점에서 누구나 쉽게 구매 가능한 캔커피입니다\n";


	SetColor((int)COLOR::GREEN, (int)COLOR::BLACK);
	cout << "몬*터: ";
	SetColor((int)COLOR::GREEN, (int)FOREGROUND_INTENSITY);
	cout << "m";
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	cout << "  에너지드링크 중 가장 인기 있는상품 입니다. 효과가 상당합니다.\n\n";

	cout << "나가기 : Space";

	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	
	while (true)
	{
		if (KeyController() == (int)KEY::SPACE)
			break;
	}
}