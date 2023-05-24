#include "MapManager.h"
#include "Stage.h"

MapManager* MapManager::Instance = nullptr;

MapManager::MapManager()
{
    for (int i = 0; i < 3; i++)
    {
        S_stage[i] = nullptr;
    }
}

MapManager::~MapManager()
{
    for (int i = 0; i < 3; i++)
    {
        SAFE_DELETE(S_stage[i]);
    }
}

bool MapManager::Init()
{
    char* C_stageName[3] = { (char*)"Stage1.txt", (char*)"Stage2.txt", (char*)"Stage3.txt"};
    //스테이지를 만든다
    for (int i = 0; i < 3; i++)
    {
        S_stage[i] = new Stage;
        if (S_stage[i]->Init(C_stageName[i])) { return false; }
    }
    return true;
}

void MapManager::Run(int i_curStage)
{
    I_curStage = i_curStage;
    S_stage[I_curStage]->Render();
}
