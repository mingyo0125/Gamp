#include "Core.h"
#include <iostream>
#include "Core.h"
using namespace std;
Core* Core::Instance = nullptr;

bool Core::Init()
{
	//Manager들 초기화
	//커서 없애기
	return true;
}

void Core::Run()
{
	int stage = MenuDraw();

	//맵 렌더링
	while (true)
	{
		//맵 계속 그리기
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
