#pragma once
const int HORIZON = 31;
const int VERTICAL = 20;

// 위치.
typedef struct _tagpos
{
	int x;
	int y;
}POS, * PPOS;

typedef struct _player 
{
	POS playerPos;       // 위치.
	POS newPos;    // 갱신된 위치.
} PLAYER, * PPLAYER;

void Asciiart();
void Render(char _map[VERTICAL][HORIZON], PPLAYER _player, int hpCnt);

enum class MAPTYPE
{
	WALL = '0', ROAD = '1', ENDL = '2', Caffeine = '3',
};

void Init(char _map[VERTICAL][HORIZON], PPLAYER _playerPos, PPOS _startPos);
void Update(char _map[VERTICAL][HORIZON], PPLAYER _playerPos, int hpCnt);
void GetItme(char item, PPLAYER _playerPos);
void MakeItem(char item, char _map[VERTICAL][HORIZON]);