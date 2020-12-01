#include "task2.h"
#include <iostream>
#include <vector>
#include <string>

void task2()
{
	system("cls");
	std::vector<std::string> names {"Jonatan", "Suzan", "Lucy", "John"};

	for (int i = 0; i < names.size(); i++)
	{
		std::string name = names.at(i);
		std::cout << name << " Initial is " << name[0] << std::endl;
		std::cout << name << " Final char is " << name[name.size()-1] << std::endl;

	}
	system("pause");
}
