#include <iostream>
using namespace std;

int main()
{
	int iNumber[9] = {};

	for (int i = 0; i < 9; i++)
	{
		iNumber[i] = i + 1;
	}

	int idx1, idx2 = 0, temp = 0;
	srand((unsigned int)time(NULL));
	//셔플
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 9;
		idx2 = rand() % 9;

		temp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = temp;
		
	}
	//cout << " * * * " << endl;
	cout << iNumber[0] << "\t" << iNumber[1] << "\t" << iNumber[2] << endl;
	
	int iStrike = 0, iBall = 0;
	int count = 1;
	int iInput[3];

	while (true)
	{
		cout << count << "회" << endl;
		cout << "1~9까지의 숫자 3개를 입력하세요 {0 : 종료}" << endl;
		cin >> iInput[0] >> iInput[1] >> iInput[2];

		//종료조건
		if (iInput[0] == 0 || iInput[1] == 0 || iInput[2] == 0)
		{
			break;
		}
		//예외처리
		else if (iInput[0] < 1 || iInput[0] > 9 ||
				 iInput[1] < 1 || iInput[1] > 9 ||
				 iInput[2] < 1 || iInput[2] > 9)
		{
			cout << "잘못된 숫자를 입력하였습니다. 1 ~ 9까지의 숫자를 입력하세요" << endl;
			continue;
		}
		else if(iInput[0] == iInput[1] ||
				iInput[1] == iInput[2] ||
				iInput[2] == iInput[0])
		{
			cout << "잘못된 숫자를 입력하였습니다. 서로 다른 1 ~ 9까지의 숫자를 입력하세요" << endl;
			continue;
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; i < 3; j++)
			{
				if (iNumber[i] == iInput[j])
				{
					if (i == j)
					{
						iStrike++;
					}
					else
					{
						iBall++;
					}
				}
			}
		}

		//정답
		if (iStrike == 3)
		{
			cout << "정답입니다";
			break;
		}
		else if(iStrike == 0 || iBall == 0)
		{
			cout << "바보";
			count++;
			continue;
		}
		else
		{
			count++;
			cout << "스트라이크 : " << iStrike << endl;
			cout << "볼 : " << iBall << endl;
			continue;
		}

	}

	//여기서부터 자율적으로 짜기

	//system("cls"); //콘솔화면 지우기
}