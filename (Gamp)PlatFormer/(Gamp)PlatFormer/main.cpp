#include<iostream>
#include "Core.h"
using namespace std;

int main()
{
	//GameManager 초기화
	if (Core::GetInstance()->Init())
	{
		cout << "Core 초기화 실패" << endl;
		Core::DestroyInstance();
		return 0;
	}

	//GameManager 실행
	Core::GetInstance()->Run();
	Core::DestroyInstance();

}