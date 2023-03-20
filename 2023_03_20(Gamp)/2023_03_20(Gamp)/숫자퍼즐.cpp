#include <iostream>
#include <conio.h>
using namespace std;

void Init(int* _pNumber)
{
	//배열 초기화
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 24; i++)
	{
		_pNumber[i] = i + 1;
	}
	_pNumber[24] = INT_MAX;

	//셔플
	int temp, idx1, idx2;
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 24; // 0~23
		idx2 = rand() % 24; // 0 ~23
		temp = _pNumber[idx1];
		_pNumber[idx1] = _pNumber[idx2];
		_pNumber[2] = temp;
	}
}

void RenderNubmer(int * _pNumber)
{
	cout << "========================================" << endl;
	cout << "\t 숫자 퍼즐 게임" << endl;
	cout << "*을 움직여서 1~24까지 퍼즐을 맞춰보세요." << endl;
	cout << "========================================" << endl;
	
	//숫자출력
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if(_pNumber)
		}
	}
}

void Update(int* pNumber)
{
	cout << "w: 위, s: 아래, a: 왼쪽, d: 오른쪽, q: 종료" << endl;
	static int iStarindex = 24;
	char input = _getch();
	switch (input)
	{
	case 'w':
	case 'W':
		if (iStarindex > 4)
		{
			pNumber[iStarindex] = pNumber[iStarindex - 5];
			pNumber[iStarindex - 5] = INT_MAX;
			iStarindex -= 5;
		}
		break;
	case 'a':
	case 'A':
		if (iStarindex % 5 != 0)
		{
			pNumber[iStarindex] = pNumber[iStarindex - 1];
			pNumber[iStarindex - 1] = INT_MAX;
			iStarindex -= 1;
		}
		break;
	case 's':
	case 'S':
		if (iStarindex > 20)
		{
			pNumber[iStarindex] = pNumber[iStarindex + 5];
			pNumber[iStarindex + 5] = INT_MAX;
			iStarindex += 5;
		}
		break;
	case 'd':
	case 'D':
		if (iStarindex % 5 != 4)
		{
			pNumber[iStarindex] = pNumber[iStarindex + 1];
			pNumber[iStarindex + 1] = INT_MAX;
			iStarindex += 1;
		}
		break;
	case 'q':
	case 'Q':
		break;

	default:
		break;
	}
}

void PuzzleCheck(int* pNumber)
{

}

int main()
{
	int iNumber[25] = {};
	Init(iNumber);

	//렌더링
	while (true)
	{
		system("cls");
		RenderNubmer(iNumber);
		Update(iNumber);
	}
}