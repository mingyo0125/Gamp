#include "Core.h"
#include <iostream>
#include "Core.h"
using namespace std;
Core* Core::Instance = nullptr;

bool Core::Init()
{
	//Manager�� �ʱ�ȭ
	//Ŀ�� ���ֱ�
	return true;
}

void Core::Run()
{
	int stage = MenuDraw();

	//�� ������
	while (true)
	{
		//�� ��� �׸���
		stage
	}
}
int Core::MenuDraw()
{
	for (int i = 0; i < 3; i++)
	{
		cout << i << ". Stage" << i << endl;
	}
	cout << "4. Exit" << endl;

	int input;
	cin >> input;

	return input;
}
