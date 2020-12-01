#include "task4.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm> // std sort

const std::string correct_test{ "ABDCABDA" }; // 8 long

class Students {
public:
	std::string name;

	void Setname() {
		std::cout << "please type your name: ";
		std::cin >> name;
	}
	void Setanswer() {
		std::cout << "please type your Answers Capitalized: ";
		std::cin >> answers;
	}
	int Calculate() {
		correct = 0;
		for (int i = 0; i < correct_test.size(); i++)
		{
			if (answers.at(i) == correct_test.at(i)) correct++;
		}
		return correct;
	}

	std::string getanswers() {
		return answers;
	}

private:
	std::string answers;
	int correct;

};

void print_file(std::vector<Students> &student) {
	std::fstream file("testresult.txt", std::ios::out);

	for (int i = 0; i < student.size(); i++)
		file << student.at(i).name << std::endl << student.at(i).getanswers() << std::endl;

	file.close();
}

void sortvector(std::vector<int> &numbers) {
	std::vector<int> sorted{};
	sorted = numbers;
	/*std::cout << "un sorted vector";
	for (int i = 0; i < sorted.size(); i++)
	{
		std::cout << sorted.at(i);
	}
	std::cout << std::endl;*/

	std::sort(sorted.begin(), sorted.end());
	numbers = sorted;
	/*std::cout << "sorted vector";
	for (int i = 0; i < sorted.size(); i++)
	{
		std::cout << sorted.at(i);
	}
	std::cout << std::endl;*/
}

void print(std::vector<Students>& student) {
	float average{0};
	int max{0};
	int min{8};
	std::vector<int> scores;
	system("cls");
	std::cout << "Student name\t\t Score\n";
	for (int i = 0; i < student.size(); i++)
	{
		scores.push_back(student.at(i).Calculate());
		//std::cout << student.at(i).name << "\t\t\t" << scores.at(i) << std::endl;
	}
	sortvector(scores);
	for (int y = scores.size()-1; y >= 0; y--) // backward foor loops, because sorting from small to big number
	{
		for (int x = 0; x < student.size(); x++)
		{
			if (scores.at(y) == student.at(x).Calculate()) {
				std::cout << student.at(x).name << "\t\t" << student.at(x).Calculate() << std::endl; // prints 2 times and not sorted
			}
		}
		
	}
	//find max, min and average
	for (int j = 0; j < scores.size(); j++)
	{
		if (scores.at(j) > max)
			max = scores.at(j);
		if (scores.at(j) < min) 
			min = scores.at(j);
		
		average += scores.at(j);
	}
	average /= scores.size();

	std::cout << "\n\nAverage:\t" << average << std::endl;
	std::cout << "Min:\t\t" << min << std::endl;
	std::cout << "Max:\t\t" << max << std::endl;
	std::cout << "Students:\t" << student.size() << std::endl;
}

void task4()
{

	system("cls");
	int student_count{0};
	std::cout << "how many students do you want to input? \n";
	std::cin >> student_count;

	std::vector<Students> student(student_count);
	std::string name;

	for (int i = 0; i < student_count; i++)
	{
		student.at(i).Setname();
		student.at(i).Setanswer();
	}
	print_file(student);
	print(student);
	system("pause");
}
