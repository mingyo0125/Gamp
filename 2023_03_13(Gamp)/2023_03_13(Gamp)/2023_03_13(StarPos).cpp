//#include <iostream>
//using namespace std;
//
//int main()
//{
//	cout << "=================" << endl;
//	cout << "��Ÿ���� ��ȭ ����" << endl;
//	cout << "=================" << endl << endl;
//
//	int iUpgrade = 0;
//
//	cout << "���� ����� ��ΰ���? : ";
//	cin >> iUpgrade;
//
//	float fPercent;
//	//0~2�� : 90%, 3~5�� 50%, 6~9�� 10%, 10�� �̻� 1%
//
//	srand((unsigned int)time(NULL));
//	fPercent = rand() % 10001 / 100.f; //100.f = float�� ��ȯ
//
//	cout << "���� ���� Upgrade : " << iUpgrade << "��" << endl;
//	cout << "���� ���� Percent : " << fPercent << "%" << endl;
//	cout << "��ȭ�Ͻðڽ��ϱ�? �� : 1, �ƴϿ� : 0" << endl;
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
//			cout << "��ȭ����" << endl;
//		}
//		else
//		{
//			cout << "��ȭ����" << endl;
//		}
//	}
//	else if (iUpgrade <= 5)
//	{
//		if (fPercent <= 50.f)
//		{
//			cout << "��ȭ����" << endl;
//		}
//		else
//		{
//			cout << "��ȭ����" << endl;
//		}
//	}
//	else if (iUpgrade <= 9)
//	{
//		if (fPercent <= 10.f)
//		{
//			cout << "��ȭ����" << endl;
//		}
//		else
//		{
//			cout << "��ȭ����" << endl;
//		}
//	}
//	else
//	{
//		if (fPercent <= 1.f)
//		{
//			cout << "��ȭ����" << endl;
//		}
//		else
//		{
//			cout << "��ȭ����" << endl;
//		}
//	}