#include<iostream>
#include<conio.h>
#include<Windows.h>

void Init(int* arr);
void Render();
void Calc(int* arr);
void Attack();
void Skip();

using namespace std;
int main()
{
	srand((unsigned int)time(NULL));
	

	cout << "설명";
	
	
	_getch();
	system("cls");
	Sleep(1000);

	while (true)
	{
		Render();
		Attack();
	}
	
	
}

void Init(int* arr)
{
	int randArr[20];

	for (int i = 0; i < 20; i++)
	{
		randArr[i] = i + 1;
	}

	for (int i = 0; i < 100; i++)
	{
		int first = rand() % 20, last = rand() % 20;

		swap(randArr[first], randArr[last]);
	}

	for (int i = 0; i < 5; i++)
	{
		arr[i] = randArr[i];
	}
}

void Render()
{
	int playerTable[5];
	int enemyTable[5];

	Init(playerTable);
	Init(enemyTable);

	for (int i = 0; i < 5; i++)
	{
		cout << playerTable[i] << " ";
	}

	cout << endl << "ai";

	for (int i = 0; i < 5; i++)
	{
		cout << enemyTable[i] << " ";
	}

	
}

void Attack()
{
	int what;
	cin >> what;

	if (what == 1)
	{
		//공격
		cout << "몇번 : ";
		int a;
		cin >> a;
	}
	Skip();
}