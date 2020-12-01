#include "password.h"
#include <iostream>
#include <string>
#include <conio.h>

char Input_char(bool &loop) {
	char input{};
	
	input = _getch();

	if (input == 13) { // checks if enter is pressed
		loop = false;
	}
	 // makes input lowercase
	if (input < 97 && input > 64)
	{
		input += 32;
	}
	return input;
}

 // compares each char while typing 
bool loginn()
{
	std::string password = "adminpass";

    int attempts{0};
	int char_correct{0};
	bool loop{ true };
	int i{ 0 };
	char input;
	int inputs{ 0 };
	while (attempts <5)
	{
		system("cls");
		std::cout << "Attempts left " << 5-attempts << std::endl << "Enter to confirm password\n";
		std::cout << "Type a password to loginn\n Password: ";
		i = 0;
		inputs = 0;
		loop = true;
		while (loop) {
			input = Input_char(loop);
			inputs++;

			/*std::cout << "inputs" << inputs << std::endl;*/

			if (input == password.at(i))
			{
				char_correct++;
			}

			std::cout << input;
			/*std::cout << "correct: " << char_correct << std::endl;*/

			if (inputs-1 > password.size()) {
				char_correct = 0;
			}
			if (i+1 >= password.size()) {
				i = 0;
			} // makes so 'i' dont goes out password size
			i++;
		}
		std::cout << " password size " << password.size();
		
		if (char_correct == password.size())
		{
			// std::cout << "password correct";
			return true;
			
		}
		//system("pause");
		attempts++;
	}
	
    return false;
}
