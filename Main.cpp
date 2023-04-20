#include <iostream>
#include <string>
#include "Header.h"
#include <fstream>

int main() {

	//create an item object
	frequencyCalc item1;

	int userInput = 0;

	//copy data from txt to dat file
	item1.copyToDat();

	
	//repeat menu until the user wishes to exit
	while (userInput != 4) {

		std::cout << "--------------------MENU--------------------" << std::endl;
		std::cout << "Please Input 1 to display the amount of a certain item" << std::endl;
		std::cout << "Please Input 2 to display every item purchased" << std::endl;
		std::cout << "Please Input 3 to display every item purchased represented as a Histogram" << std::endl;
		std::cout << "Please Input 4 to quit" << std::endl;

		std::cin >> userInput;

		//input validation for anything not 1 2 3 or 4
		if (userInput != 1 && userInput != 2 && userInput != 3 && userInput !=4) {
			std::cout << "Please enter a valid input of 1, 2, 3, or 4" << std::endl;
			std::cin.clear();
			std::cin.ignore(1000000000, '\n');
		}
			else if (userInput == 1) {
				item1.optionOne();
			}

			else if (userInput == 2) {
				item1.optionTwo();
			}
			else if(userInput == 3){
				item1.optionThree();
			}
		
	}
	
	

		return 0;
	}