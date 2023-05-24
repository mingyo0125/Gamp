#pragma once
#include "define.h"
#include "Stage.h"
class MapManager
{
private:
	MapManager();
	~MapManager();
private:
	static MapManager* Instance;
public:
	static MapManager* GetInst()
	{
		if (Instance == nullptr)
			Instance = new MapManager;
		return Instance;
	}
	static void DestroyInst() { SAFE_DELETE(Instance); }
private:
	Stage* S_stage[3];
	int I_curStage; //현재 스테이지
public:
	Stage* GetStage() { return S_stage[I_curStage]; }
public:
	bool Init();
	void Run(int I_curStage);
};

