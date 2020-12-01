#include "task5.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>


static constexpr int UP = 72;
static constexpr int DOWN = 80;
static constexpr int LEFT = 75;
static constexpr int RIGHT = 77;
static constexpr int SPACE = 32;
static constexpr int ENTER= 13;
const char arrow{ 'V' };
const char BLANK{ ' ' };

bool loop{ true };

void Writefile(std::vector<char>& board) {
	std::fstream file("sentence.txt", std::ios::out);
	for (int i = 0; i < board.size(); i++)
	{
		file << board.at(i);
	}
	std::cout << "\nWritten to file 'sentence.txt'\n";
	file.close();
	loop = false;
}

void changeNumber(bool up, std::vector<char> &board, int &location) {
	if (board.at(location) == BLANK && up == true)
	{
		board.at(location) = 'A'; // if space is blank then put an A
	}
	else if (up == true)board.at(location) += 1; 
	else if (up == false && board.at(location) != BLANK) board.at(location) -= 1;
}

void move(std::vector<char> &board, int &location) {
	switch (_getch()) {
	case UP:
		changeNumber(true, board, location);
		break;
	case DOWN:
		changeNumber(false, board, location);
		break;
	case LEFT:
		if (location > 0) location -= 1;
		break;
	case RIGHT:
		if (location < board.size()-1) location += 1;
		break;
	case SPACE:
		board.at(location) = BLANK;
		break;
	case ENTER:
		Writefile(board);

		break;
	}
}

void printboard(std::vector<char> &board, int &location) {
	for (int j = 0; j < 2; j++)
	{
		std::cout << "\t\t";
		for (int i = 0; i < board.size(); i++)
		{
			if (j == 0) {
				std::cout << "| ";
				if (location == i) std::cout << arrow;
				else std::cout << " ";
				std::cout << " | ";
			}
			if (j == 1) std::cout << "| " << board.at(i) << " | ";
		}
		std::cout << std::endl;
	}
}

std::string getpassword(std::vector<char> &board) {
	std::string password;
	password.clear();
	for (int i = 0; i < board.size(); i++) password += board.at(i);
	return password;
}



void task5() {

	system("cls");
	int location{ 0 };
	int size{0};

	std::cout << "How many chars will your sentence be? (including space)\n";
	std::cin >> size;

	std::vector <char> board;
	for (int i = 0; i < size; i++)
	{
		board.push_back(BLANK);
	}

	while (loop)
	{
		system("cls");
		printboard(board, location);
		std::cout << "\nPress enter to confirm sentence\n";
		move(board, location);
	}
	system("pause");
}

