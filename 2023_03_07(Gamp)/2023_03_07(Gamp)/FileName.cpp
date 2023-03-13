#include<iostream>
using namespace std;

int main()
{
	int nansu;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		nansu = rand() % 21 + 10; //10 ~ 30±îÁö
		cout << nansu << endl;
	}


}