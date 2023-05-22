#pragma once

#include<iostream>
#include "define.h"

class Core
{
private:
	Core();

private:
	static Core* Instance;
public:
	static Core* GetInstance()
	{
		if (Instance == nullptr) { Instance = new Core; };
		return Instance;
	}
	static void DestroyInstance()
	{
		SAFE_DELETE(Instance);
	}
public:
	bool Init();
	void Run();
	int MenuDraw();
};

