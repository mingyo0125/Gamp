#include "Core.h"
#include <iostream>
#include "Core.h"
#include "MapManager.h"

using namespace std;
Core* Core::Instance = nullptr;

Core::Core()
{

}

bool Core::Init()
{
	//Manager�� �ʱ�ȭ
	//Ŀ�� ���ֱ�
	if (!MapManager::GetInst()->Init())
	{
		return false;
	}
	return true;
}

void Core::Run()
{
	int I_stage = MenuDraw();

	//�� ������
	while (true)
	{
		//�� ��� �׸���

		MapManager::GetInst()->Run(I_stage - 1);
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
