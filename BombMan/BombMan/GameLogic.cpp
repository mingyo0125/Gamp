#include<iostream>
#include<vector>
#include<io.h>
#include<fcntl.h>
#include<Windows.h>
#include<algorithm>
#include "GameLogic.h"
#include "console.h"
using namespace std;
void Asciiart()
{
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"	██████╗  ██████╗ ███╗   ███╗██████╗     ███╗   ███╗ █████╗ ███╗   ██╗ " << endl;
	wcout << L"	██╔══██╗██╔═══██╗████╗ ████║██╔══██╗    ████╗ ████║██╔══██╗████╗  ██║ " << endl;
	wcout << L"	██████╔╝██║   ██║██╔████╔██║██████╔╝    ██╔████╔██║███████║██╔██╗ ██║ " << endl;
	wcout << L"	██╔══██╗██║   ██║██║╚██╔╝██║██╔══██╗    ██║╚██╔╝██║██╔══██║██║╚██╗██║ " << endl;
	wcout << L"	██████╔╝╚██████╔╝██║ ╚═╝ ██║██████╔╝    ██║ ╚═╝ ██║██║  ██║██║ ╚████║ " << endl;
	wcout << L"	╚═════╝  ╚═════╝ ╚═╝     ╚═╝╚═════╝     ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝ " << endl;
	int Curmode = _setmode(_fileno(stdout), prevmode);


}

void Init(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer, PPOS _pStartpos, PPOS _pEndpos)
{
	system("mode con cols=80 lines=30");
	// 제목 설정.
	SetConsoleTitle(TEXT("2-1 Bombman"));
	ConsoleCursor(false, 1);
	_pStartpos->x = 0;
	_pStartpos->y = 0;
	_pEndpos->x = 19;
	_pEndpos->y = 13;
	PLAYER tSetplayer = { *_pStartpos,{}, 1, 0, false, false, false };
	*_pPlayer = tSetplayer;
	// string copy.. 0: 벽, 1: 길, 2: 시작지점, 3: 끝지점
	strcpy_s(_cMaze[0], "21100000000000000000");
	strcpy_s(_cMaze[1], "10111111111000000000");
	strcpy_s(_cMaze[2], "00100000001111100000");
	strcpy_s(_cMaze[3], "00100000000000100000");
	strcpy_s(_cMaze[4], "00100000000000100000");
	strcpy_s(_cMaze[5], "00100000000000100000");
	strcpy_s(_cMaze[6], "00100000000000100000");
	strcpy_s(_cMaze[7], "00100000000000100000");
	strcpy_s(_cMaze[8], "00111111111000100000");
	strcpy_s(_cMaze[9], "00000000001000100000");
	strcpy_s(_cMaze[10], "00111111111000100000");
	strcpy_s(_cMaze[11], "00100000000000100000");
	strcpy_s(_cMaze[12], "00111111111111100000");
	strcpy_s(_cMaze[13], "00001000000000001113");
	strcpy_s(_cMaze[14], "00001000000000001000");
	strcpy_s(_cMaze[15], "00001000000000001000");
	strcpy_s(_cMaze[16], "00001111111111111000");
	strcpy_s(_cMaze[17], "00001000000000000000");
	strcpy_s(_cMaze[18], "00001000000000000000");
	strcpy_s(_cMaze[19], "00000000000000000000");
}

void Update(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer, vector<BOOM>& _vecBomb, vector<POS>& _boomEffect)
{
	// ========== 움직임 로직 ======//
	// 
	// 갱신된 위치(NewPos)가 현재 위치를 저장.
	_pPlayer->tNewPos = _pPlayer->tPos;
	// GetAsyncKeyState
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		--_pPlayer->tNewPos.y;
		Sleep(100);
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		++_pPlayer->tNewPos.y;
		Sleep(100);
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		--_pPlayer->tNewPos.x;
		Sleep(100);
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		++_pPlayer->tNewPos.x;
		Sleep(100);
	}
	// 벽 밖인지 clamp
	_pPlayer->tNewPos.x = std::clamp(_pPlayer->tNewPos.x, 0, HORIZON - 2);
	_pPlayer->tNewPos.y = std::clamp(_pPlayer->tNewPos.y, 0, VERTICAL - 1);

	if (_cMaze[_pPlayer->tNewPos.y][_pPlayer->tNewPos.x] != '0') // 0은 벽.
	{
		_pPlayer->tPos = _pPlayer->tNewPos;
	}

	// 벽은 한칸만 밀 수 있다.  => 다음칸이 벽이고, 다음다음칸이 길일때만 밀 수 있다.
	// 
	else if (_cMaze[_pPlayer->tNewPos.y][_pPlayer->tNewPos.x] == (char)MAPTYPE::WALL && _pPlayer->bPushOnOff && _pPlayer->bWallPush)
	{
		POS tDiffpos = { _pPlayer->tNewPos.x - _pPlayer->tPos.x, _pPlayer->tNewPos.y - _pPlayer->tPos.y };
		POS tNextpos = { _pPlayer->tPos.x + tDiffpos.x * 1, _pPlayer->tPos.y + tDiffpos.y * 1 };
		POS tDoublepos = { _pPlayer->tPos.x + tDiffpos.x * 2, _pPlayer->tPos.y + tDiffpos.y * 2 };

		if (_pPlayer->bSlime && _cMaze[tDoublepos.y][tDoublepos.x] == (char)MAPTYPE::WALL)
		{
			_pPlayer->tPos = _pPlayer->tNewPos;
		}
		else if (_cMaze[tDoublepos.y][tDoublepos.x] == (char)MAPTYPE::ROAD)
		{
			_cMaze[tDoublepos.y][tDoublepos.x] = (char)MAPTYPE::WALL;
			_cMaze[tNextpos.y][tNextpos.x] = (char)MAPTYPE::ROAD;
			_pPlayer->tPos = _pPlayer->tNewPos;
		}
	}
	else if (_pPlayer->bSlime)
	{
		_pPlayer->tPos = _pPlayer->tNewPos;
	}

	if (Getitem(_cMaze[_pPlayer->tPos.y][_pPlayer->tPos.x], _pPlayer))
		_cMaze[_pPlayer->tPos.y][_pPlayer->tPos.x] = (char)MAPTYPE::ROAD;

	// 슬라임을 먹었을 때, 푸시를 할 수 있을 때

	// ========== 키 로직 ======//
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		BombCreate(_cMaze, _pPlayer, _vecBomb);
	}

	// 폭탄을 터트릴거야. life
	int iBombcount = _pPlayer->iBombcount;
	for (int i = 0; i < iBombcount; i++)
	{
		BOOM& boomItem = _vecBomb[i];
		boomItem.life--;
		// 0~4 / 5~9 
		boomItem.life % 10 >= 5 ? _cMaze[boomItem.y][boomItem.x] = (char)MAPTYPE::WATERBOMB :
			_cMaze[boomItem.y][boomItem.x] = (char)MAPTYPE::TWINKLE;
		//boomItem.life % 2 == 0? _cMaze[boomItem.y][boomItem.x] = (char)MAPTYPE::WATERBOMB :
		//	_cMaze[boomItem.y][boomItem.x] = (char)MAPTYPE::TWINKLE;

		if (boomItem.life <= 0)
		{
			// life <=0  터트리면돼.
			boomItem.bDie = true;
			_pPlayer->iBombcount--;
			// 터트리면돼. 터지면서? 폭탄위치 + 파워 -> 길 / 확률상 아이템 나오기.
			Fire(_cMaze, _pPlayer, { boomItem.x, boomItem.y }, _boomEffect);

			// 벡터에서 지우기도 해야함. => 추후 따로 할 예정.
		}
	}
	if (GetAsyncKeyState('E') & 0x8000)
	{
		if (_pPlayer->bWallPush)
			_pPlayer->bPushOnOff = !_pPlayer->bPushOnOff;
	}
	Sleep(100);
}

void Render(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer, vector<POS>& _boomEffect)
{
	for (int i = 0; i < VERTICAL; i++)
	{
		for (int j = 0; j < HORIZON; j++)
		{
			for (int k = 0; k < _boomEffect.size(); k++)
			{
				bool drawed = false;
				//이펙트의 범위만큼
				if (_boomEffect[k].x == j && _boomEffect[k].y == i)
				{
					SetColor((int)COLOR::LIGHT_BLUE, (int)COLOR::BLACK);
					cout << "▤";
					drawed = true;
					break;
				}

				if (drawed)
				{
					continue;
				}
			}
			if (_pPlayer->tPos.x == j && _pPlayer->tPos.y == i)
				cout << "§";
			else if (_cMaze[i][j] == (char)MAPTYPE::WALL)
				cout << "■";
			else if (_cMaze[i][j] == (char)MAPTYPE::ROAD)
				cout << " "; // 윈도우11 한칸S
			else if (_cMaze[i][j] == (char)MAPTYPE::START)
				cout << "®";
			else if (_cMaze[i][j] == (char)MAPTYPE::END)
				cout << "♨";
			else if (_cMaze[i][j] == (char)MAPTYPE::WATERBOMB) // 물풍선
			{
				SetColor((int)COLOR::MINT, (int)COLOR::BLACK);
				cout << "＠";
			}
			else if (_cMaze[i][j] == (char)MAPTYPE::TWINKLE) // 
			{
				SetColor((int)COLOR::SKYBLUE, (int)COLOR::BLACK);
				cout << "⊙";
			}
			else if (_cMaze[i][j] == (char)MAPTYPE::POWER)
				cout << "◐";
			else if (_cMaze[i][j] == (char)MAPTYPE::SLIME)
				cout << "♤";
			else if (_cMaze[i][j] == (char)MAPTYPE::PUSH)
				cout << "▩";
			SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
		}
		cout << endl;
	}
	cout << "SPACEBAR: 폭탄설치, E: 푸시능력 ON/OFF" << endl;
	cout << "폭탄 파워: " << _pPlayer->iBombPower << endl;
	if (_pPlayer->bPushOnOff)
		cout << "푸시 능력: ON " << endl;
	else
		cout << "푸시 능력: OFF" << endl;
	if (_pPlayer->bSlime)
		cout << "슬라임 능력: ON " << endl;
	else
		cout << "슬라임 능력: OFF" << endl;
}

void BombCreate(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer, std::vector<BOOM>& _vecBomb)
{
	// 폭탄 개수는 5개만 하고 싶어.
	if (_pPlayer->iBombcount == 5) return;

	// 폭탄 설치 가능
	if (_cMaze[_pPlayer->tPos.y][_pPlayer->tPos.x] == (char)MAPTYPE::ROAD)
	{
		_cMaze[_pPlayer->tPos.y][_pPlayer->tPos.x] = 'b';
		_pPlayer->iBombcount++;
		// 초기화 방법 3가지 있습니다.
		_vecBomb.push_back({ _pPlayer->tPos.x, _pPlayer->tPos.y, 20, false });
	}
}

void Fire(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer, POS _boompos, std::vector<POS>& _boomEffect)
{
	// 현재 포지션을 일단 길로 바꿔야돼.
	_cMaze[_boompos.y][_boompos.x] = (char)MAPTYPE::ROAD;
	// 물폭탄 맞았으면 죽어야돼. -> game over .. (0,0)으로 강제 이동시킵시다.
	// clamp 여기서 하자.
	int iScopexmin = _boompos.x - _pPlayer->iBombPower;
	int iScopexmax = _boompos.x + _pPlayer->iBombPower;
	int iScopeymin = _boompos.y - _pPlayer->iBombPower;
	int iScopeymax = _boompos.y + _pPlayer->iBombPower;

	// x로 죽은거 || y로 죽은거
	if ((_pPlayer->tPos.x >= iScopexmin && _pPlayer->tPos.x <= iScopexmax && _pPlayer->tPos.y == _boompos.y) ||
		(_pPlayer->tPos.y >= iScopeymin && _pPlayer->tPos.y <= iScopeymax && _pPlayer->tPos.x == _boompos.x))
		_pPlayer->tPos = { 0,0 };

	// 파워만큼 상하좌우를 고려해야돼.
	// 예외처리 clamp
	static vector<POS> veceffect;
	for (int i = iScopexmin; i <= iScopexmax; i++)
	{
		veceffect.push_back({ std::clamp(i, 0, HORIZON - 2),_boompos.y });
	}
	for (int i = iScopeymin; i <= iScopeymax; i++)
	{
		veceffect.push_back({ _boompos.x, std::clamp(i, 0, VERTICAL - 1) });
	}

	// 아이템.
	for (const auto& target : veceffect)
	{
		_boomEffect.push_back(target);
		if (_cMaze[target.y][target.x] == (char)MAPTYPE::WALL)
		{
			// 50% 확률로 아이템이나와
			// 25% : 15% : 10% = 물풍선, 푸시, 슬라임
			float fRandomitem = rand() % 10001 / 100.f; // 0.0% ~ 100.0%
			if (fRandomitem <= 50.f)
			{
				fRandomitem = rand() % 10001 / 100.f;
				if (fRandomitem <= 50.f)
				{
					_cMaze[target.y][target.x] = (char)MAPTYPE::POWER;
				}
				else if (fRandomitem <= 80.f)
				{
					_cMaze[target.y][target.x] = (char)MAPTYPE::SLIME;
				}
				else
				{
					_cMaze[target.y][target.x] = (char)MAPTYPE::PUSH;
				}
			}
			else
				_cMaze[target.y][target.x] = (char)MAPTYPE::ROAD;
		}
	}

}

void Event(std::vector<BOOM>& _vecBomb, std::vector<POS>& _boomEffect)
{

	// 폭탄을 지울거야.
	vector<BOOM>::iterator iter;
	//for ( ; iter == _vecBomb.begin(); iter--)
	//{
	//	if (iter->bDie)
	//	{
	//		iter = _vecBomb.erase(iter);
	//	}
	//}
	for (iter = _vecBomb.begin(); iter != _vecBomb.end(); )
	{
		if (iter->bDie)
		{
			iter = _vecBomb.erase(iter);
		}
		else
			iter++;
	}

	vector<POS>::iterator effectiter;
	for (effectiter = _boomEffect.begin(); effectiter != _boomEffect.end();)
	{
		effectiter = _boomEffect.erase(effectiter);
	}

}

bool Getitem(char _cItem, PPLAYER _pPlayer)
{
	if (_cItem == (char)MAPTYPE::POWER)
	{
		// 사운드
		++_pPlayer->iBombPower;
		return true;
	}
	else if (_cItem == (char)MAPTYPE::SLIME)
	{
		_pPlayer->bSlime = true;
		return true;
	}
	else if (_cItem == (char)MAPTYPE::PUSH)
	{
		_pPlayer->bWallPush = true;
		_pPlayer->bPushOnOff = true;
		return true;
	}
	return false;
}