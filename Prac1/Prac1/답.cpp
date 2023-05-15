#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

// �̱���, ���� �˰��� ���, ���ݰ� ��ŵ�� ����, ����ó�� ��...tlqkf?

int phase = 1, rround = 1, p_hp = 2, a_hp = 2;	// ������, ����, ü��
int player[5] = {}, ai[5] = {};	// �迭

void Random(int* realArray)		// ���� �������ְ� �־��ִ� �޼���
{
	int _array[20] = {};	// 1 ~ 20���� �Ǿ� �ϱ� ������
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

	for (int i = 0; i < 5; i++)		// �����Ѱ� �־��ֱ�
	{
		realArray[i] = _array[i];
	}
}

int Average(int* realArray) {		// ��� �����ִ� �޼���
	int average = 0;

	for (int i = 0; i < 5; i++)
	{
		average += realArray[i];
	}
	average /= 5;

	return average;
}

// showHP() �޼��� ����� ������? �׳� �� ��� �����ٷ���.. �̰� �Ｎ�����ϴϱ�

void Render() {		// ���״�� ����, ���ڵ� ǥ������
	cout << "[[[ ���� ������ : " << phase << " ]]]" << endl;
	cout << "<<< ���� ���� : " << rround << " >>>" << endl << endl;

	cout << "���� PLAYER ������ : " << p_hp << endl;
	cout << "==========Player=======" << endl;
	cout << "Player�� ���� ��� : " << Average(player) << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << player[i] << " ";
	}

	cout << endl << endl << "���� AI ������ : " << a_hp << endl;
	cout << "==========AI=======" << endl;
	cout << "Ai�� ���� ��� : " << Average(ai) << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << ai[i] << " ";
	}

	cout << endl << endl << "�̹� ���忡 ������ �� ���?\n"
		<< "1. ����, 2. ��ŵ" << endl;
}

void Skip() {		// ��ŵ. �Ƹ� �������� ��ŵ�� ��� �������� �ض� ���� ��? �Ѵ� ��ŵ�ض� ��� �� �ʸ� ��ŵ�Ƕ� ��
	cout << "��ŵ�Ǿ����!" << endl;
	rround++;
	Sleep(1000);
}

void Attack() {	// ���ݰ� ����ó��
	int attack = 0;
	cout << "������ ���� �������ּ���(1~5���� ����) : ";
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

void input_1() {		// �������� ��ŵ���� ������ ����ó��
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
		cout << "�߸��� ���̿���. �ٽ� �Է����ּ��� : ";
	}
}

void AiChoose() {		// ai�� ����
	srand((unsigned int)time(NULL));
	int choose = (rand() % 2) + 1;	// 1, 2
	int num = 0;
	if (choose == 1) {
		// ����
		while (true) {
			num = (rand() % 5) + 1;	// 1, 2, 3, 4, 5
			if (player[num] != 0) {
				cout << "ai�� " << num << "�� ������ϴ�." << endl;
				player[num - 1] = 0;
				Sleep(1000);
				break;
			}
		}
	}
	else if (choose == 2) {
		cout << "AI�� ��ŵ�߾��!" << endl;
		rround++;
		Sleep(1000);
	}
}

int main() {
	cout << "=============" << endl;
	cout << "GGM ī�� ����" << endl;
	cout << "=============" << endl;
	cout << "���� ���� : ������ ī�带 ������ ���, ��հ��� ���� ���ӿ��� �¸��ϼ���!\n"
		<< "������ �����Ϸ��� �ƹ�Ű�� ��������.\n";
	char start = _getch();		// Ű �Է����� ���۵�
	system("cls");
	Random(ai);
	Random(player);
	int p = phase;

	while (true) {
		if (rround != 4) {
			if (p != phase) {		// ���� ���ο� �������̸� �ٽ� ����
				srand((unsigned int)time(NULL));		// �ٽ� �������ֱ� �����õ� �� ����
				Random(player);
				Random(ai);
				p = phase;
			}
			Render();	// �ϴ� �׷��ְ�
			input_1();		// �Է� �ް�
			if (rround != 4) {	// ���尡 3���Ǿ� �ϱ� ������ Ȯ���ѹ� �� ����
				AiChoose();
			}
			system("cls");
		}
		else if (rround == 4) {	// ������ ���� �����̸�
			if (Average(player) < Average(ai)) {
				cout << "�÷��̾� �¸�!" << endl;
				a_hp--;
			}
			else if (Average(player) > Average(ai)) {
				cout << "ai �¸�!" << endl;
				p_hp--;
			}

			phase++;
			rround = 0;
			Sleep(1000);
			system("cls");

			if (p_hp == 0 || a_hp == 0) {		// hp �� ���� �̰������ �Ǵ�����
				if (p_hp == 0) {
					cout << "���������� ai �¸�!";
					break;
				}
				if (a_hp == 0) {
					cout << "���������� player �¸�!";
					break;
				}
			}
		}
	}
}