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
	//Manager들 초기화
	//커서 없애기
	if (!MapManager::GetInst()->Init())
	{
		return false;
	}
	return true;
}

void Core::Run()
{
	int I_stage = MenuDraw();

	//맵 렌더링
	while (true)
	{
		//맵 계속 그리기

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
