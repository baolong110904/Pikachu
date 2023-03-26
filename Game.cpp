#include <iostream>
#include "Game.h"
#include <windows.h>
#include <conio.h>
#include <fstream>
#include<stdio.h>
#include<Windows.h>
#include <string>
#include <chrono>

#define _EASY 4
#define _MEDIUM 6

using namespace std;

const int size = _EASY;

void printInterface();

void HideConsoleCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}
void gotoxy(int x, int y){
	COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
enum Consolecolor {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Yellow = 6,
    White = 7,
    Gray = 8,
    DarkBlue = 9,
    DarkGreen = 10,
    Teal = 11,
    DarkRed = 12,
    Purple = 13,
    Orange = 14,
    LightGray = 15,
    DarkOrange = 16,
    LightBlue = 17,
    LightGreen = 18,
    LightYellow = 19,
    LightCyan = 20,
    Pink = 21,
    Lavender = 22
    
};

void setcolor(Consolecolor color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (WORD)color);
}
void drawlogo() {
	setcolor(Orange);
	gotoxy(0,0);
	unsigned char logo[] = R"(
	 .----------------.  .----------------.  .----------------.  .----------------.  .-----------------.
	| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |
	| |   _____      | || |     ____     | || |    ______    | || |     _____    | || | ____  _____  | |
	| |  |_   _|     | || |   .'    `.   | || |  .' ___  |   | || |    |_   _|   | || ||_   \|_   _| | |
	| |    | |       | || |  /  .--.  \  | || | / .'   \_|   | || |      | |     | || |  |   \ | |   | |
	| |    | |   _   | || |  | |    | |  | || | | |    ____  | || |      | |     | || |  | |\ \| |   | |
	| |   _| |__/ |  | || |  \  `--'  /  | || | \ `.___]  _| | || |     _| |_    | || | _| |_\   |_  | |
	| |  |________|  | || |   `.____.'   | || |  `._____.'   | || |    |_____|   | || ||_____|\____| | |
	| |              | || |              | || |              | || |              | || |              | |
	| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |
	 '----------------'  '----------------'  '----------------'  '----------------'  '----------------' 
	)";
	cout << logo;
}

void printrectangle(int left, int top, int width, int height){
	gotoxy(left, top);
	putchar(218);
	for (int i = 0; i < width; i++)
		putchar(196);
	putchar(191);

	int i = 0;
	for (; i < height; i++)
	{
		gotoxy(left, top + i + 1);
		putchar(179);
		gotoxy(left + width + 1, top + i + 1);
		putchar(179);
	}

	gotoxy(left, top + i);
	putchar(192);
	for (i = 0; i < width; i++)
		putchar(196);
	putchar(217);
}
void setConsolecolor(int textColor, int bgColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (textColor + (bgColor * 16)));
}
void Game::saveData() {
    std::ofstream outfile("player_info.dat", std::ios::out | std::ios::binary);
    if (!outfile) {
        std::cerr << "Failed to open file for writing.\n";
        return;
    }

    // Write data to binary file
    outfile.write((char*)&playerName, sizeof(playerName));
    outfile.write((char*)&playerID, sizeof(playerID)); 
    outfile.write((char*)&playerClass, sizeof(playerClass));

    outfile.close();
    cout << "Data saved to file.\n";
    system("cls");
}
void Game::setupGame() {
	system("cls");
	// Print rectangle to cover the screen
	printrectangle(15, 13, 80, 12);
	drawlogo();
	ShowCursor(true);
	
	gotoxy(25, 15);
	cout << "Please enter your name shortly, under 10 characters!";
	gotoxy(35, 18);
	cout << "Enter your name:  ";
	cin >> playerName;
	gotoxy(35, 20);
	cout << "Enter your ID:  ";
	while (!(cin >> playerID)) {
	gotoxy(0, 27);
    cout << "Please enter a valid integer for your ID! ";
    gotoxy(51, 20);
	cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	gotoxy(35, 22);
	cout << "Enter your class's name:  ";
	cin >> playerClass;
	system("cls");
	saveData();
//// Set mode based on difficulty level
//	if (_mode == 4)
//		strcpy_s(mode, "EASY");
//	else 
//		strcpy_s(mode, "MEDIUM");
}

void createBackground(string filename){
	string* background;	
	ifstream bg;
	bg.open(filename);
	int i = 0;
	while (!bg.eof()) {
		getline(bg, background[i]);
		i++;
	}
	bg.close();
}
void printBackground(string* background, int size) {
    for (int i = 0; i < size; i++) {
        cout << background[i] << endl;
    }
}

void Game::printInterface()
{
	
//	board->showBoard();
//	board->buildBoardData();
//	board->renderBoard();
	system("cls");
	bool Loop = 1;
	ShowCursor(false);
	while(Loop){ 
	    printrectangle(59, 1, 33, 10);
		printrectangle(59, 12, 33, 10);
		
		printrectangle(60, 2, 31, 2);
	   
		gotoxy(67, 3);
		cout << "PLAYER'S INFORMATION";
		
		gotoxy(65, 5);
		if(playerName.empty()) {
		    playerName = "unknown";
		    cout << "Player's name: " << playerName;
		} else {
		    cout << "Player's name: " << playerName;
		}
		gotoxy(65, 7);
		if(playerID == 0) {
		    playerID = -1;
		    cout << "Student's ID: unknown";
		} else {
		    cout << "Student's ID: " << playerID;
		}
		gotoxy(65, 9);
		if(playerClass.empty()) {
		    playerClass = "unknown";
		    cout << "Class: " << playerClass;
		} else {
		    cout << "Class: " << playerClass;
		}
		
		
		printrectangle(60, 13, 31, 2);
		
		gotoxy(69, 14);
		cout << "GAME INFORMATION";
		
		gotoxy(65, 16);
		cout << "Moves:";
		gotoxy(65, 17);
		cout << "Current score:";
		gotoxy(80, 17);
		cout << score;
		
		printrectangle(59, 24, 33, 2);
		printrectangle(59, 27, 14, 2);
		printrectangle(78, 27, 14, 2);
		
		gotoxy(67, 25);
		cout << "M : Move suggestion";
		
		gotoxy(63, 28);
		cout << "H : Help";
		gotoxy(81, 28);
		cout << "Esc : Exit";
		HideConsoleCursor();
	}
			
}
void Game::startGame() 
{
	system("cls");
	while(isPlaying = true){
		printInterface();
	}
	saveData();
}

