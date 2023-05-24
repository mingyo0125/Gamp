#pragma once
#include "define.h"

class Stage
{
public:
	Stage();
	~Stage();
private:
	char C_stage[HEIGHT][WIDTH];
	POINT P_start;
	POINT P_end;
public:
	POINT GetStart() { return P_start; }
	POINT GetEnd() { return P_end; }
	char GetBlock(int x, int y) { return C_stage[y][x]; }
public:
	bool Init(char* _fileName);
	void Render();
};


