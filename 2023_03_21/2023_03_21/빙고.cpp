#include<iostream>
#include<Windows.h>
using namespace std;
//���� ����ؼ� ��ǲ�̶� ������ �� �ε����� max�� ��ȯ �߽��� �ٽ� �̱�
enum class AI_MODE
{
	AM_EASY = 1,
	AM_NORMAL
};
void Init(int* _pNumber)
{
	// �迭 �ʱ�ȭ �ϰ� ..
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 25; i++)
		_pNumber[i] = i + 1;
	// ����
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 25; // 0~24
		idx2 = rand() % 25; // 0~24
		iTemp = _pNumber[idx1];
		_pNumber[idx1] = _pNumber[idx2];
		_pNumber[idx2] = iTemp;
	}
}

// ��, �ּ�, ����
void RenderNumber(int* _pNumber, int _iBingo, int _AiBingo)
{
	cout << "==================================" << endl;
	cout << " |\t ���� ����\t " << endl;
	cout << "==================================" << endl;
	cout << "�������� 5�� �̻��� �Ǹ� ���ӿ��� �¸��մϴ�." << endl;
	cout << "==================================" << endl;
	// ���ڸ� ����Ұž�.
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (_pNumber[i * 5 + j] == INT_MAX)
				cout << "*" << "\t";
			else if(_pNumber[i * 5 + j] == INT_MIN)
				cout << "X" << "\t";
			else
				cout << _pNumber[i * 5 + j] << "\t";
		}
		cout << endl;
	}
	cout << "Bingo Line: " << _iBingo << endl;
	cout << "AI Bingo Line: " << _AiBingo << endl;
}

void AI(int * _pNumber)
{
	srand((unsigned int)time(NULL));
	int a = rand() % 25;

	for (int i = 0; i < 25; i++)
	{
		if (a == _pNumber[i])
		{
			_pNumber[i] = INT_MIN;
		}
	}

}

void Update(int* _pNumber, int& _iInput)
{
	// 1�����迭..
	for (int i = 0; i < 25; i++)
	{
		if (_iInput == _pNumber[i])
		{
			_pNumber[i] = INT_MAX;
		}
	}
}

int CountBingo(int* _pNumber)
{
	// ����....
	int iCheckBingo = 0;
	int iHorStar = 0, iVerStar = 0, iLTStar = 0, iRTStar = 0;
	for (int i = 0; i < 5; i++)
	{
		iHorStar = iVerStar = 0;
		for (int j = 0; j < 5; j++)
		{
			if (_pNumber[i * 5 + j] == INT_MAX)
				iHorStar++;
			if (_pNumber[j * 5 + i] == INT_MAX)
				iVerStar++;
		}
		if (iHorStar == 5)
			iCheckBingo++;
		if (iVerStar == 5)
			iCheckBingo++;

	}
	// �밢��
	for (int i = 0; i < 25; i += 6)
	{
		if (_pNumber[i] == INT_MAX)
			iLTStar++;
	}
	if (iLTStar == 5)
		iCheckBingo++;

	for (int i = 4; i <= 20; i += 4)
	{
		if (_pNumber[i] == INT_MAX)
			iRTStar++;
	}
	if (iRTStar == 5)
		iCheckBingo++;
	return iCheckBingo;

}

int AICountBingo(int* _pNumber)
{
	int iCheckBingo = 0;
	int iHorStar = 0, iVerStar = 0, iLTStar = 0, iRTStar = 0;
	for (int i = 0; i < 5; i++)
	{
		iHorStar = iVerStar = 0;
		for (int j = 0; j < 5; j++)
		{
			if (_pNumber[i * 5 + j] == INT_MIN)
				iHorStar++;
			if (_pNumber[j * 5 + i] == INT_MIN)
				iVerStar++;
		}
		if (iHorStar == 5)
			iCheckBingo++;
		if (iVerStar == 5)
			iCheckBingo++;

	}
	for (int i = 0; i < 25; i += 6)
	{
		if (_pNumber[i] == INT_MIN)
			iLTStar++;
	}
	if (iLTStar == 5)
		iCheckBingo++;

	for (int i = 4; i <= 20; i += 4)
	{
		if (_pNumber[i] == INT_MIN)
			iRTStar++;
	}
	if (iRTStar == 5)
		iCheckBingo++;
	return iCheckBingo;

}

int main()
{
	int iNumber[25] = {};
	int iBingo = 0;
	int AiBingo = 0;
	int iInput;
	Init(iNumber);

	while (true)
	{
		system("cls");
		RenderNumber(iNumber, iBingo, AiBingo);

		if (iBingo >= 5)
		{
			cout << "���ӿ��� �¸��ϼ̽��ϴ�." << endl;
			break;
		}
		else if(AiBingo >= 5)
		{
			cout << "���ӿ��� �й��ϼ̽��ϴ�." << endl;
			break;
		}
		cout << "���ڸ� �Է��ϼ���.(0: ����)" << endl;
		cin >> iInput;
		// ����ó��.
		if (iInput == 0)
		{
			cout << "������ �����մϴ�." << endl;
			break;
		}
		else if (iInput < 1 || iInput > 25)
		{
			cout << "�߸��Է��ϼ̽��ϴ�." << endl;
			continue;
		}
		// Update() ĭ�� ä���ش�, ä���� ĭ���� Ȯ��. �츮�� ������ �ִ� ���ڸ� ȭ��󿡼� *�� �ٲ���.
		Update(iNumber, iInput);
		iBingo = CountBingo(iNumber);
		AiBingo = AICountBingo(iNumber);
		AI(iNumber);
	}
}