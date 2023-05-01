#pragma once
// 20 X 20 
// 장점: 숫자보다(상수보다) 가독성이 좋다.
//       메모리에 올라가지 않는다.
// 단점: 메모리에 올라가지 않는다.
// 매크로를 만드는 경우.
//#define HORIZON  20
//#define VERTICAL 20
// 변수 4가지
// 1. 지역변수
// 2. 전역변수
// 3. 정적변수(static)
// 4. 외부변수(extern)
const int HORIZON = 21;
const int VERTICAL = 20;

// 위치.
typedef struct _tagpos
{
	int x;
	int y;
}POS, * PPOS;

// 플레이어.
typedef struct _tagplayer
{
	POS tPos;       // 위치.
	int iBombPower; // 폭탄 파워.
	int iBombcount; // 폭탄 개수.
	bool bSlime;    // 슬라임.
	bool bWallPush; // 벽푸시.
	bool bPushOnOff;// 벽 밀기 스위치.
}PLAYER, * PPLAYER;

// 폭탄
typedef struct _tagboom
{
	int x;
	int y;
	int life;
}BOOM, * PBOOM;
void Asciiart();
void Init(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer, PPOS _pStartpos, PPOS _pEndpos);
void Update(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer);
void Render(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer);
enum class MAPTYPE
{
	WALL = '0', ROAD = '1',
	START = '2', END = '3'
};