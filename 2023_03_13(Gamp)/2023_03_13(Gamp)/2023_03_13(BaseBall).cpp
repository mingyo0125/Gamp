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
	//����
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
		cout << count << "ȸ" << endl;
		cout << "1~9������ ���� 3���� �Է��ϼ��� {0 : ����}" << endl;
		cin >> iInput[0] >> iInput[1] >> iInput[2];

		//��������
		if (iInput[0] == 0 || iInput[1] == 0 || iInput[2] == 0)
		{
			break;
		}
		//����ó��
		else if (iInput[0] < 1 || iInput[0] > 9 ||
				 iInput[1] < 1 || iInput[1] > 9 ||
				 iInput[2] < 1 || iInput[2] > 9)
		{
			cout << "�߸��� ���ڸ� �Է��Ͽ����ϴ�. 1 ~ 9������ ���ڸ� �Է��ϼ���" << endl;
			continue;
		}
		else if(iInput[0] == iInput[1] ||
				iInput[1] == iInput[2] ||
				iInput[2] == iInput[0])
		{
			cout << "�߸��� ���ڸ� �Է��Ͽ����ϴ�. ���� �ٸ� 1 ~ 9������ ���ڸ� �Է��ϼ���" << endl;
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

		//����
		if (iStrike == 3)
		{
			cout << "�����Դϴ�";
			break;
		}
		else if(iStrike == 0 || iBall == 0)
		{
			cout << "�ٺ�";
			count++;
			continue;
		}
		else
		{
			count++;
			cout << "��Ʈ����ũ : " << iStrike << endl;
			cout << "�� : " << iBall << endl;
			continue;
		}

	}

	//���⼭���� ���������� ¥��

	//system("cls"); //�ܼ�ȭ�� �����
}