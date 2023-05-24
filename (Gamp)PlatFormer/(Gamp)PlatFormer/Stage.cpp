#include "Stage.h"
#include <fstream>
using namespace std;

bool Stage::Init(char* _fileName)
{
    //파일을 불러온다
    ifstream readFile;
    if (readFile.is_open()) { return false; }

    readFile.open(_fileName);

    for (int i = 0; i < HEIGHT; i++)
    {
        readFile.getline(C_stage[i], WIDTH + 1); //들어갈 버퍼 위치, 크기
        for (int j = 0; j < WIDTH; j++)
        {
            if (C_stage[i][j] == (char)STAGE_BLOCK_TYPE::START)
            {
                P_start.x = j;
                P_start.y = i;
            }
            if (C_stage[i][j] == (char)STAGE_BLOCK_TYPE::END)
            {
                P_end.x = j;
                P_end.y = i;
            }
            
        }
    }

    return false;
}

void Stage::Render()
{
}
