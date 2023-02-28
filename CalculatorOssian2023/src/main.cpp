#include "includes.h"

void clear()
{
	std::cout << "\x1B[2J\x1B[H";

}

int main()
{
	double result;
	std::array<char, 11> numbers = {
		'1',
		'2',
		'3',
		'4',
		'5',
		'6',
		'7',
		'8',
		'9',
		'0',
		','
	};
	//Numbers 
	
	//useable expressions
	std::array<double, 4> expressions = {
		'+',
		'-',
		'/',
		'*'
	};

	std::vector<std::string> listOfNumbers;
	std::vector<char> listOfExpressions;
	

	// for user input.
	std::string input = "";
	char switchInput = ' ';
	//for number and expression keeping
	std::string pushNumber;
	// bool for easy exit
	bool isRunning = true;
	while (isRunning)
	{

		std::cout << "Welcome to Ossians calculator in 2023 \n";
		//Give user options to what they'd like.
		std::cout << "1. Use calculator\n";
		std::cout << "2. Exit\n";

		std::cin >> switchInput;
		std::cout << "\n";

		//clear everything for another run
		listOfExpressions.clear();
		input.clear();
		pushNumber.clear();
		listOfExpressions.clear();

		switch (switchInput)
		{
		case '1':
			//use the calculator
			clear();
			std::cout << "Write what'd you want to calculate.\n";
			std::cin.ignore();
			//get the user input for calcutation
			std::getline(std::cin, input);

			for (int i = 0; i < input.size()-1; i++)
			{
				//check every char of the input for numbers or expressions
				for (int j = 0; j < numbers.size(); j++)
				{
					if (input[i] == numbers[j])
					{
						//add char from input to string that we're keeping
						pushNumber.push_back(input[i]);
					}
				}

				//if input[i] is a expression
				for (int j = 0; j < expressions.size(); j++)
				{
					if (input[i] == expressions[j])
					{
						//push expression and numbers to vector
						listOfNumbers.push_back(pushNumber);
						listOfExpressions.push_back(input[i]);
						//reset pushNumber for new number
						pushNumber = "";
					}
				}
				
				//end of input size for
			}
			for (int j = 0; j < numbers.size(); j++)
			{
				if (input[input.size()-1] == numbers[j])
				{
					//same thing as before but last number
					pushNumber.push_back(input[input.size()-1]);
					listOfNumbers.push_back(pushNumber);
				}
			}

			
			for (int i = 0; i < (listOfNumbers.size()); i++)
			{
				if (listOfExpressions[0] == '+')
				{
					result = std::stod(listOfNumbers[0]) + std::stod(listOfNumbers[1]);
					listOfNumbers.erase(std::next(listOfNumbers.begin()));
					listOfNumbers.erase(listOfNumbers.begin());
					listOfExpressions.erase(listOfExpressions.begin());
				}
	
				if (listOfExpressions[0] == '-')
				{
					result = std::stod(listOfNumbers[0]) - std::stod(listOfNumbers[1]);
					listOfNumbers.erase(std::next(listOfNumbers.begin()));
					listOfNumbers.erase(listOfNumbers.begin());
					listOfExpressions.erase(listOfExpressions.begin());
				}
				if (listOfExpressions[0] == '/')
				{
					result = std::stod(listOfNumbers[0]) / std::stod(listOfNumbers[1]);
					listOfNumbers.erase(std::next(listOfNumbers.begin()));
					listOfNumbers.erase(listOfNumbers.begin());
					listOfExpressions.erase(listOfExpressions.begin());
				}
				if (listOfExpressions[0] == '*')
				{
					result = std::stod(listOfNumbers[0]) * std::stod(listOfNumbers[1]);
					listOfNumbers.erase(std::next(listOfNumbers.begin()));
					listOfNumbers.erase(listOfNumbers.begin());
					listOfExpressions.erase(listOfExpressions.begin());
				}
			}

			std::cout << "\n" << result;
			std::cin.ignore();
			std::cin;
			
			break;

		case '2':
			//exit the program
			std::cout << "exiting program....\n";
			std::cin;
			return 0;
		
		default: 
			clear();
			break;
		}


	}
	//should never reach here. 
	return 0;
}