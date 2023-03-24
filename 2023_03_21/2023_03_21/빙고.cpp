#include<iostream>
#include<Windows.h>
using namespace std;
//셔플 사용해서 인풋이랑 같으면 그 인덱스를 max로 전환 멕스면 다시 뽑기
enum class AI_MODE
{
	AM_EASY = 1,
	AM_NORMAL
};
void Init(int* _pNumber)
{
	// 배열 초기화 하고 ..
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 25; i++)
		_pNumber[i] = i + 1;
	// 셔플
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

// 값, 주소, 참조
void RenderNumber(int* _pNumber, int _iBingo, int _AiBingo)
{
	cout << "==================================" << endl;
	cout << " |\t 빙고 게임\t " << endl;
	cout << "==================================" << endl;
	cout << "빙고줄이 5줄 이상이 되면 게임에서 승리합니다." << endl;
	cout << "==================================" << endl;
	// 숫자를 출력할거야.
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
	// 1차원배열..
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
	// 빙고....
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
	// 대각선
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
			cout << "게임에서 승리하셨습니다." << endl;
			break;
		}
		else if(AiBingo >= 5)
		{
			cout << "게임에서 패배하셨습니다." << endl;
			break;
		}
		cout << "숫자를 입력하세요.(0: 종료)" << endl;
		cin >> iInput;
		// 예외처리.
		if (iInput == 0)
		{
			cout << "게임을 종료합니다." << endl;
			break;
		}
		else if (iInput < 1 || iInput > 25)
		{
			cout << "잘못입력하셨습니다." << endl;
			continue;
		}
		// Update() 칸을 채워준다, 채워진 칸인지 확인. 우리가 가지고 있는 숫자를 화면상에서 *로 바꿔줌.
		Update(iNumber, iInput);
		iBingo = CountBingo(iNumber);
		AiBingo = AICountBingo(iNumber);
		AI(iNumber);
	}
}