#include <iostream>
#include <conio.h>
using namespace std;

void timegame()
{
	time_t Curtime = time(NULL);

	while (true)
	{
		if (_kbhit())
		{
			cout << "��" << endl;
			break;
		}
	}

	if (time(NULL) - Curtime == 10)
	{
		cout << "����";
	}
	else if (time(NULL) - Curtime > 0)
	{
		cout << "������";
	}
	else
	{
		cout << "����";
	}

}

int main()
{
	cout << "�ð� ������ ����" << endl;
	cout << "�ð��� ��� �����Դϴ�." << endl;
	cout << "ó�� Ű�� ���߿� ���� Ű ������ �ð��� 10�ʷ� ����� �ξ����ϴ�." << endl;
	cout << "�ƹ��ų� ��������" << endl;
	timegame();
}