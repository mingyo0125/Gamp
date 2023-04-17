#include"bombman.h"
#include<Windows.h>
#include<conio.h>
#include<iostream>

using namespace std;

int main() {
	Asciiart();
    
    // Get handle to standard output
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Set cursor position to (x,y) = (10,5)
    COORD cursorPosition = { 30, 12 };
    SetConsoleCursorPosition(hConsole, cursorPosition);
    cout << "게임 시작";

    //SetConsoleCursorPosition();

    _getch();
        
    return 0;
}