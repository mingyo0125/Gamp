#include "Stage.h"
#include <fstream>
using namespace std;

bool Stage::Init(char* _fileName)
{
    //������ �ҷ��´�
    ifstream readFile;
    if (readFile.is_open()) { return false; }

    readFile.open(_fileName);

    for (int i = 0; i < HEIGHT; i++)
    {
        readFile.getline(C_stage[i], WIDTH + 1); //�� ���� ��ġ, ũ��
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
