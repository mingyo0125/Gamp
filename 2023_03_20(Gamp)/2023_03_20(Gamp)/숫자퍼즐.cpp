#include <iostream>
#include <conio.h>
using namespace std;

void Init(int* _pNumber)
{
	//�迭 �ʱ�ȭ
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 24; i++)
	{
		_pNumber[i] = i + 1;
	}
	_pNumber[24] = INT_MAX;

	//����
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
	cout << "\t ���� ���� ����" << endl;
	cout << "*�� �������� 1~24���� ������ ���纸����." << endl;
	cout << "========================================" << endl;
	
	//�������
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
	cout << "w: ��, s: �Ʒ�, a: ����, d: ������, q: ����" << endl;
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

	//������
	while (true)
	{
		system("cls");
		RenderNubmer(iNumber);
		Update(iNumber);
	}
}