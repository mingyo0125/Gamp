#pragma once
#include<Windows.h>

#define SAFE_DELETE(Instance) if (Instance) {delete Instance; Instance = nullptr; }
#define WIDTH 50
#define HEIGHT 10

enum class STAGE_BLOCK_TYPE
{
	WALL = '0',
	ROAD = '1',
	START = '2',
	END = '3',
	COIN = '4'
};