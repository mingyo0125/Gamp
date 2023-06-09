#pragma once
const int HORIZON = 31;
const int VERTICAL = 20;

// ��ġ.
typedef struct _tagpos
{
	int x;
	int y;
}POS, * PPOS;

typedef struct _player 
{
	POS playerPos;       // ��ġ.
	POS newPos;    // ���ŵ� ��ġ.
} PLAYER, * PPLAYER;

void Asciiart();
void Render(char _map[VERTICAL][HORIZON], PPLAYER _player);

enum class MAPTYPE
{
	WALL = '0', ROAD = '1', ENDL = '2', Caffeine = '3',
};

void Init(char _map[VERTICAL][HORIZON], PPLAYER _player, PPOS _sttartpos);
void Update(char _map[VERTICAL][HORIZON], PPLAYER _player);
