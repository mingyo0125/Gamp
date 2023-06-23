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


enum class MAPTYPE
{
	WALL = '0', ROAD = '1', ENDL = '2', COFFEE = '3', MONSTER = '4', CHERRY = '5', SPINACH = '6', ALMOND = '7'
};

void Asciiart();
void Render(char _map[VERTICAL][HORIZON], PPLAYER _player, int &hpCnt);
void Init(char _map[VERTICAL][HORIZON], PPLAYER _playerPos, PPOS _startPos);
void Update(char _map[VERTICAL][HORIZON], PPLAYER _playerPos, int &hpCnt, bool &isGameOver);
void GetItme(char item, PPLAYER _playerPos, int &hpCnt);
void MakeItem(char item, char _map[VERTICAL][HORIZON]);
void GameOver(bool &isGameOver);