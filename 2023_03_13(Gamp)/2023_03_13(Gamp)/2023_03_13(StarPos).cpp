//#include<iostream>
//using namespace std;
//
//int main()
//{
//	cout << " ================= " << endl;
//	cout << " ��Ÿ���� ��ȭ ����" << endl;
//	cout << " ================= " << endl;
//	int iUpgrade = 0;
//	cout << "���� ����� ��ΰ���?: ";
//	cin >> iUpgrade;
//	srand((unsigned int)time(NULL));
//	float fPercent = rand() % 10001 / 100.f;
//	cout << fPercent;
//
//	// 0~2��: 90% Ȯ��, 3~5��: 50%, 6~9��: 10%, 10����: 1% Ȯ���� ����
//	cout << "���� ���� Upgrade: " << iUpgrade << "��" << endl;
//	cout << "��ȭ Ȯ�� Percent: " << fPercent << "%" << endl;
//	cout << "��ȭ�Ͻðڽ��ϱ�? ��: 1, �ƴϿ�: 0" << endl;
//
//	int iInput; 
//	cin >> iInput;
//
//	if (iInput == 0)
//		return 0;
//	if (iUpgrade <= 2) // 90% �̱⸦ ����.
//		if (fPercent <= 90.f)
//			cout << "��ȭ ����" << endl;
//		else
//			cout << "��ȭ ����" << endl;
//	if (iUpgrade <= 2) // 90% �̱⸦ ����.
//		if (fPercent <= 90.f)
//			cout << "��ȭ ����" << endl;
//		else
//			cout << "��ȭ ����" << endl;
//
//
//}