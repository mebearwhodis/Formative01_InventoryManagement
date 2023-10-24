#include <iostream>
#include <string>
#include "Utils.h"

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

int ValidNumber(const std::string& question, const int min, const int max)
{
	std::string answer;
	bool restartLoop = true;
	do
	{
		restartLoop = true;

		std::cout << std::endl << question << std::endl;
		std::cin >> answer;
		for (int i = 0; i < answer.size(); i++)
		{
			if (!isdigit(answer[i]))
			{
				std::cout << std::endl << "Please enter a valid number." << std::endl << std::endl;
				restartLoop = false;
			}
			if (restartLoop && i == answer.size() - 1)
			{
				if (std::stoi(answer) > max || std::stoi(answer) < min)
				{
					std::cout << std::endl << "Please enter a valid number." << std::endl << std::endl;
					restartLoop = false;
				}
				else
				{
					restartLoop = true;
				}
			}
		}
	} while (!restartLoop);

	return std::stoi(answer);
}