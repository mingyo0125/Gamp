#include<iostream>
#include "Core.h"
using namespace std;

int main()
{
	//GameManager �ʱ�ȭ
	if (Core::GetInstance()->Init())
	{
		cout << "Core �ʱ�ȭ ����" << endl;
		Core::DestroyInstance();
		return 0;
	}

	//GameManager ����
	Core::GetInstance()->Run();
	Core::DestroyInstance();

}