//#include<iostream>
//using namespace std;
//
//int main()
//{
//	cout << " ================= " << endl;
//	cout << " 스타포스 강화 게임" << endl;
//	cout << " ================= " << endl;
//	int iUpgrade = 0;
//	cout << "현재 무기는 몇성인가요?: ";
//	cin >> iUpgrade;
//	srand((unsigned int)time(NULL));
//	float fPercent = rand() % 10001 / 100.f;
//	cout << fPercent;
//
//	// 0~2성: 90% 확률, 3~5성: 50%, 6~9성: 10%, 10성↑: 1% 확률로 성공
//	cout << "현재 무기 Upgrade: " << iUpgrade << "성" << endl;
//	cout << "강화 확률 Percent: " << fPercent << "%" << endl;
//	cout << "강화하시겠습니까? 예: 1, 아니오: 0" << endl;
//
//	int iInput; 
//	cin >> iInput;
//
//	if (iInput == 0)
//		return 0;
//	if (iUpgrade <= 2) // 90% 이기를 원해.
//		if (fPercent <= 90.f)
//			cout << "강화 성공" << endl;
//		else
//			cout << "강화 실패" << endl;
//	if (iUpgrade <= 2) // 90% 이기를 원해.
//		if (fPercent <= 90.f)
//			cout << "강화 성공" << endl;
//		else
//			cout << "강화 실패" << endl;
//
//
//}