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


enum class MAPTYPE
{
	WALL = '0', ROAD = '1', ENDL = '2', Caffeine = '3',
};

void Asciiart();
void Render(char _map[VERTICAL][HORIZON], PPLAYER _player, float &hpCnt);
void Init(char _map[VERTICAL][HORIZON], PPLAYER _playerPos, PPOS _startPos);
void Update(char _map[VERTICAL][HORIZON], PPLAYER _playerPos, float&hpCnt);
void GetItme(char item, PPLAYER _playerPos, float &hpCnt);
void MakeItem(char item, char _map[VERTICAL][HORIZON]);
void GameOver();