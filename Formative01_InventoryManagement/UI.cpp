#include <iostream>
#include <string>

// Asks a Yes/No question, returns true if yes, false if no
bool YesNoQuestion(const std::string& question)
{
	bool restartLoop = true;
	do
	{
		restartLoop = true;
		char answer;

		std::cout << std::endl << question << " Y/N" << std::endl;
		std::cin >> answer;

		switch (tolower(answer))
		{
		case 'y':
			return true;
		case 'n':
			return false;
		default:
			std::cout << std::endl << "Please enter a valid answer: Y/N" << std::endl << std::endl;
			restartLoop = false;
		}
	} while (!restartLoop);

	return false;
}

