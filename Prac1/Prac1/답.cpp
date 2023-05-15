#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

// 싱글톤, 셔플 알고리즘 사용, 공격과 스킵은 랜덤, 예외처리 등...tlqkf?

int phase = 1, rround = 1, p_hp = 2, a_hp = 2;	// 페이즈, 라운드, 체력
int player[5] = {}, ai[5] = {};	// 배열

void Random(int* realArray)		// 랜덤 셔플해주고 넣어주는 메서드
{
	int _array[20] = {};	// 1 ~ 20까지 되야 하기 때문에
	for (int i = 0; i < 20; i++)
		_array[i] = i + 1;

	int temp, index1, index2;
	for (int i = 0; i < 100; i++)
	{
		index1 = rand() % 20; // 0 ~ 19
		index2 = rand() % 20; // 0 ~ 19

		temp = _array[index1];
		_array[index1] = _array[index2];
		_array[index2] = temp;
	}

	for (int i = 0; i < 5; i++)		// 셔플한거 넣어주기
	{
		realArray[i] = _array[i];
	}
}

int Average(int* realArray) {		// 평균 구해주는 메서드
	int average = 0;

	for (int i = 0; i < 5; i++)
	{
		average += realArray[i];
	}
	average /= 5;

	return average;
}

// showHP() 메서드 만들면 좋을뜻? 그냥 뭐 모양 보여줄려고.. 이건 즉석가능하니까

void Render() {		// 말그대로 랜더, 글자들 표시해줌
	cout << "[[[ 현재 페이즈 : " << phase << " ]]]" << endl;
	cout << "<<< 현재 라운드 : " << rround << " >>>" << endl << endl;

	cout << "현재 PLAYER 라이프 : " << p_hp << endl;
	cout << "==========Player=======" << endl;
	cout << "Player의 현재 평균 : " << Average(player) << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << player[i] << " ";
	}

	cout << endl << endl << "현재 AI 라이프 : " << a_hp << endl;
	cout << "==========AI=======" << endl;
	cout << "Ai의 현재 평균 : " << Average(ai) << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << ai[i] << " ";
	}

	cout << endl << endl << "이번 라운드에 무엇을 할 까요?\n"
		<< "1. 공격, 2. 스킵" << endl;
}

void Skip() {		// 스킵. 아마 조건으로 스킵을 어떻게 랜덤으로 해라 나올 뜻? 둘다 스킵해라 어느 한 쪽만 스킵되라 등
	cout << "스킵되었어요!" << endl;
	rround++;
	Sleep(1000);
}

void Attack() {	// 공격과 예외처리
	int attack = 0;
	cout << "공격할 수를 선택해주세요(1~5까지 가능) : ";
	cin >> attack;
	if (cin.fail() || attack <= 0 || attack >= 6) {
		cin.clear();
		cin.ignore(1000, '\n');
		Skip();
		return;
	}

	ai[attack - 1] = 0;
	rround++;
	Sleep(1000);
}

void input_1() {		// 공격인지 스킵인지 결정과 예외처리
	int answer = 0;
	while (true) {
		cin >> answer;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
		}
		if (answer == 1) {
			Attack();
			break;
		}
		else if (answer == 2) {
			Skip();
			return;
			break;
		}
		cout << "잘못된 값이예요. 다시 입력해주세요 : ";
	}
}

void AiChoose() {		// ai의 선택
	srand((unsigned int)time(NULL));
	int choose = (rand() % 2) + 1;	// 1, 2
	int num = 0;
	if (choose == 1) {
		// 공격
		while (true) {
			num = (rand() % 5) + 1;	// 1, 2, 3, 4, 5
			if (player[num] != 0) {
				cout << "ai가 " << num << "를 골랐습니다." << endl;
				player[num - 1] = 0;
				Sleep(1000);
				break;
			}
		}
	}
	else if (choose == 2) {
		cout << "AI가 스킵했어요!" << endl;
		rround++;
		Sleep(1000);
	}
}

int main() {
	cout << "=============" << endl;
	cout << "GGM 카드 게임" << endl;
	cout << "=============" << endl;
	cout << "게임 설명 : 상대방의 카드를 총으로 쏘고, 평균값을 낮춰 게임에서 승리하세요!\n"
		<< "게임을 시작하려면 아무키나 누르세요.\n";
	char start = _getch();		// 키 입력으로 시작됨
	system("cls");
	Random(ai);
	Random(player);
	int p = phase;

	while (true) {
		if (rround != 4) {
			if (p != phase) {		// 만약 새로운 페이즈이면 다시 설정
				srand((unsigned int)time(NULL));		// 다시 설정해주기 랜덤시드 재 생성
				Random(player);
				Random(ai);
				p = phase;
			}
			Render();	// 일단 그려주고
			input_1();		// 입력 받고
			if (rround != 4) {	// 라운드가 3번되야 하기 때문에 확인한번 더 해줌
				AiChoose();
			}
			system("cls");
		}
		else if (rround == 4) {	// 게임이 끝날 조건이면
			if (Average(player) < Average(ai)) {
				cout << "플레이어 승리!" << endl;
				a_hp--;
			}
			else if (Average(player) > Average(ai)) {
				cout << "ai 승리!" << endl;
				p_hp--;
			}

			phase++;
			rround = 0;
			Sleep(1000);
			system("cls");

			if (p_hp == 0 || a_hp == 0) {		// hp 로 누가 이겼는지를 판단해줌
				if (p_hp == 0) {
					cout << "최종적으로 ai 승리!";
					break;
				}
				if (a_hp == 0) {
					cout << "최종적으로 player 승리!";
					break;
				}
			}
		}
	}
}