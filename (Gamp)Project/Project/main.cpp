#include <iostream>
#include "Console.h"
#include "GameLogic.h"

using namespace std;;
int main()
{
	char map[VERTICAL][HORIZON] = {};
	PLAYER player = {};
	POS startpos = {};
	Init(map, &player, &startpos);

	while (true)
	{
		Gotoxy(0, 0);
		system("cls");
		//Asciiart();
		
		
		Render(map, &player);
		Update(map, &player);
	
	
	}
}
