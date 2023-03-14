#include<iostream>
using namespace std;

int main()
{
	int iNumber[9] = {};
	for (int i = 0; i < 9; i++)
		iNumber[i] = i + 1;

	int idx1, idx2, temp;
	srand((unsigned int)time(NULL));
	// 셔플을 할거야.
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 9;
		idx2 = rand() % 9;
		//		cout << idx1 << " " << idx2 << endl;
		temp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = temp;
	}
	//cout << "* * *" << endl;
	cout << iNumber[0] << "\t" <<
		iNumber[1] << "\t" << iNumber[2] << endl;
	int iStrike = 0, iBall = 0;
	int iCnt = 1;
	int iStrike2 = 0, iBall2 = 0;
	int iCnt2 = 1;
	bool isFirstP = true;
	int iInput[3];

	while (true)
	{
		if (isFirstP)
		{
			cout << "player 1" << endl;
			cout << iCnt << " 회" << endl;
			cout << "1 ~ 9 숫자 중 숫자 3개를 입력하세요.(0: 종료): ";
			cin >> iInput[0] >> iInput[1] >> iInput[2];

			// 종료 조건
			if (iInput[0] == 0 || iInput[1] == 0 || iInput[2] == 0)
				break;

			// 예외 처리1
			else if (iInput[0] < 1 || iInput[0] > 9 ||
				iInput[1] < 1 || iInput[1] > 9 ||
				iInput[2] < 1 || iInput[2] > 9)
			{
				cout << "잘못된 숫자를 입력하였습니다. 1~9 범위의 숫자를 입력하세요." << endl;
				continue;
			}
			// 예외 처리2
			else if (iInput[0] == iInput[1] ||
				iInput[1] == iInput[2] ||
				iInput[2] == iInput[0])
			{
				cout << "중복된 숫자를 입력하였습니다. 금집니다 금지!!." << endl;
				continue;
			}
			// 여기서부터 자율적으로 짜기
			iStrike = iBall = 0;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (iNumber[i] == iInput[j])
					{
						if (i == j)
							iStrike++;
						else
							iBall++;
						//strike, ball
					}
				}
			}

			if (iStrike == 3)
			{
				system("cls"); // 콘솔 화면 지우기
				cout << "숫자를 모두 맞췄습니다 축하합니다 ㅎㅎ" << endl;
				break;
			}
			else if (iStrike == 0 && iBall == 0)
				cout << "Out입니다! " << endl;
			else
				system("cls"); // 콘솔 화면 지우기
			cout << iStrike << "strike " << iBall << "ball" << endl;
			isFirstP = (isFirstP == true) ? false : true;
			iCnt++;
		}
		else
		{
			cout << "player 2" << endl;
			cout << iCnt2 << " 회" << endl;
			cout << "1 ~ 9 숫자 중 숫자 3개를 입력하세요.(0: 종료): ";
			cin >> iInput[0] >> iInput[1] >> iInput[2];

			// 종료 조건
			if (iInput[0] == 0 || iInput[1] == 0 || iInput[2] == 0)
				break;

			// 예외 처리1
			else if (iInput[0] < 1 || iInput[0] > 9 ||
				iInput[1] < 1 || iInput[1] > 9 ||
				iInput[2] < 1 || iInput[2] > 9)
			{
				cout << "잘못된 숫자를 입력하였습니다. 1~9 범위의 숫자를 입력하세요." << endl;
				continue;
			}
			// 예외 처리2
			else if (iInput[0] == iInput[1] ||
				iInput[1] == iInput[2] ||
				iInput[2] == iInput[0])
			{
				cout << "중복된 숫자를 입력하였습니다. 금집니다 금지!!." << endl;
				continue;
			}
			// 여기서부터 자율적으로 짜기
			iStrike2 = iBall2 = 0;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (iNumber[i] == iInput[j])
					{
						if (i == j)
							iStrike2++;
						else
							iBall2++;
						//strike, ball
					}
				}
			}

			if (iStrike2 == 3)
			{
				system("cls"); // 콘솔 화면 지우기
				cout << "숫자를 모두 맞췄습니다 축하합니다 ㅎㅎ" << endl;
				break;
			}
			else if (iStrike2 == 0 && iBall2 == 0)
				cout << "Out입니다! " << endl;
			else
				system("cls"); // 콘솔 화면 지우기
			cout << iStrike2 << "strike " << iBall2 << "ball" << endl;
			isFirstP = (isFirstP == true) ? false : true;
			iCnt2++;
		}
	}
}


