//#include <iostream>
//using namespace std;
//
//int main()
//{
//	cout << "=================" << endl;
//	cout << "스타포스 강화 게임" << endl;
//	cout << "=================" << endl << endl;
//
//	int iUpgrade = 0;
//
//	cout << "현재 무기는 몇성인가요? : ";
//	cin >> iUpgrade;
//
//	float fPercent;
//	//0~2성 : 90%, 3~5성 50%, 6~9성 10%, 10성 이상 1%
//
//	srand((unsigned int)time(NULL));
//	fPercent = rand() % 10001 / 100.f; //100.f = float형 변환
//
//	cout << "현재 무기 Upgrade : " << iUpgrade << "성" << endl;
//	cout << "현재 무기 Percent : " << fPercent << "%" << endl;
//	cout << "강화하시겠습니까? 예 : 1, 아니오 : 0" << endl;
//
//	int iInput;
//	cin >> iInput;
//
//	if (iInput == 0) { return 0; }
//
//	if (iUpgrade <= 2)
//	{
//		if (fPercent <= 90.f)
//		{
//			cout << "강화성공" << endl;
//		}
//		else
//		{
//			cout << "강화실패" << endl;
//		}
//	}
//	else if (iUpgrade <= 5)
//	{
//		if (fPercent <= 50.f)
//		{
//			cout << "강화성공" << endl;
//		}
//		else
//		{
//			cout << "강화실패" << endl;
//		}
//	}
//	else if (iUpgrade <= 9)
//	{
//		if (fPercent <= 10.f)
//		{
//			cout << "강화성공" << endl;
//		}
//		else
//		{
//			cout << "강화실패" << endl;
//		}
//	}
//	else
//	{
//		if (fPercent <= 1.f)
//		{
//			cout << "강화성공" << endl;
//		}
//		else
//		{
//			cout << "강화실패" << endl;
//		}
//	}