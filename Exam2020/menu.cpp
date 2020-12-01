#include "menu.h"
#include <iostream>
#include <conio.h>
#include <vector>

#include "task2.h"
#include "task4.h"
#include "task5.h"

static constexpr int UP = 72;
static constexpr int DOWN = 80;
static constexpr int ENTER = 13;

std::vector<std::string> board{
				"1.Print names Initials and ends (task2)", 
				"2.Students exam result(task4)", 
				"3.Typing a sentence(task5)", 
				"4.Terminate the program(Quit)"};


void Printmenu(int location) {
	std::cout << "Use arrow keys or 'w' 's' to move the arrow. Enter to choose\n\n";
	for (int i = 0; i < board.size(); i++)
	{
		if (i == location)
		{
			std::cout << " --> ";
		}
		std::cout << board.at(i) << std::endl;
	}
}

void menu()
{
	int location{ 0 };
	while (true)
	{
		system("cls");
		Printmenu(location);
		//std::cout << location;
		switch (_getch())
		{
		case UP: case 'w':
			if (location > 0)
			{
				location--;
			}
			break;
		case DOWN: case 's':
			if (location < 3)
			{
				location++;
			}
			break;
		case ENTER:
			switch (location+1)
			{
			case 1:
				task2();
				break;
			case 2:
				task4();
				break;
			case 3:
				task5();
				break;
			case 4:
				std::exit(0);
				break;
			}
			break;
		}
	}
	

}
