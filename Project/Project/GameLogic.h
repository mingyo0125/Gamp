#pragma once
const int HORIZON = 20;
const int VERTICAL = 20;

// 위치.
typedef struct _tagpos
{
	int x;
	int y;
}POS, * PPOS;

typedef struct _player 
{
	POS tPos;       // 위치.
	POS tNewPos;    // 갱신된 위치.
} PLAYER, * PPLAYER;

void Asciiart();
void Render(char _map[VERTICAL][HORIZON], PPLAYER _player);

enum class MAPTYPE
{
	WALL = '0', ROAD = '1',
};

void Init(char _map[VERTICAL][HORIZON], PPLAYER _player, PPOS _sttartpos);
