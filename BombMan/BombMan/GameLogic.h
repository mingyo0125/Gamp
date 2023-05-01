#pragma once
// 20 X 20 
// ����: ���ں���(�������) �������� ����.
//       �޸𸮿� �ö��� �ʴ´�.
// ����: �޸𸮿� �ö��� �ʴ´�.
// ��ũ�θ� ����� ���.
//#define HORIZON  20
//#define VERTICAL 20
// ���� 4����
// 1. ��������
// 2. ��������
// 3. ��������(static)
// 4. �ܺκ���(extern)
const int HORIZON = 21;
const int VERTICAL = 20;

// ��ġ.
typedef struct _tagpos
{
	int x;
	int y;
}POS, * PPOS;

// �÷��̾�.
typedef struct _tagplayer
{
	POS tPos;       // ��ġ.
	int iBombPower; // ��ź �Ŀ�.
	int iBombcount; // ��ź ����.
	bool bSlime;    // ������.
	bool bWallPush; // ��Ǫ��.
	bool bPushOnOff;// �� �б� ����ġ.
}PLAYER, * PPLAYER;

// ��ź
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