#pragma once
/*   20 X 20
	 ����: ���ں���(�������)�������� ����
		   �޸𸮿� �ö��� �ʴ´�.
	 ����: �޸𸮿� �ö��� �ʴ´�.
	 ��ũ�θ� ����� ���
	 #define HRIZON 20
	 #define VERTICAL 20
	 ���� 4����
	 1. ��������
	 2. ��������
	 3. ��������(static)
	 4. �ܺκ���(extern)
	 struct
	 �ϳ��� �ڷ���, c��Ÿ�� ������� ������ �ǵ帮�� ������ �߻��� �� �ִ�.
*/


const int HORIZON = 21;
const int VERTICAL = 20;
typedef struct _tagpos
{
	int x;
	int y;
}POS, *PPOS;

// ����ü
typedef struct Mystruct
{
	POS tPos; //��ġ.
	int iBombPower;
	int iBombcount;
	bool bSlime;
	bool bWallPush;
	bool bPushOnOff;
}PLAYER, *PPLAYER;
//��ź
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