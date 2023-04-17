#pragma once
/*   20 X 20
	 장점: 숫자보다(상수보다)가독성이 좋다
		   메모리에 올라가지 않는다.
	 단점: 메모리에 올라가지 않는다.
	 매크로를 만드는 경우
	 #define HRIZON 20
	 #define VERTICAL 20
	 변수 4가지
	 1. 지역변수
	 2. 전역변수
	 3. 정적변수(static)
	 4. 외부변수(extern)
	 struct
	 하나의 자료형, c스타일 사용으로 설정을 건드리면 오류가 발생할 수 있다.
*/


const int HORIZON = 21;
const int VERTICAL = 20;
typedef struct _tagpos
{
	int x;
	int y;
}POS, *PPOS;

// 구조체
typedef struct Mystruct
{
	POS tPos; //위치.
	int iBombPower;
	int iBombcount;
	bool bSlime;
	bool bWallPush;
	bool bPushOnOff;
}PLAYER, *PPLAYER;
//폭탄
typedef struct _tagboom
{
	int x;
	int y;
	int life;
}BOOM, *PBOOM;
void Asciiart();
void Init(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer, PPOS _pStartpos, PPOS _pEndpos);
void Update(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer);
void Render(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer);
enum class MAPTYPE
{
	WALL = '0', 
	ROAD = '1',
	START = '2', 
	END = '3',
};