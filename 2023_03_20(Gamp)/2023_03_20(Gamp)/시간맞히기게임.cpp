#include <iostream>
#include <conio.h>
using namespace std;

void timegame()
{
	time_t Curtime = time(NULL);

	while (true)
	{
		if (_kbhit())
		{
			cout << "끝" << endl;
			break;
		}
	}

	if (time(NULL) - Curtime == 10)
	{
		cout << "정답";
	}
	else if (time(NULL) - Curtime > 0)
	{
		cout << "느렸음";
	}
	else
	{
		cout << "빠름";
	}

}

int main()
{
	cout << "시간 맞히기 게임" << endl;
	cout << "시간을 재는 게임입니다." << endl;
	cout << "처음 키와 나중에 누른 키 사이의 시간을 10초로 만들어 두었습니다." << endl;
	cout << "아무거나 누르세요" << endl;
	timegame();
}