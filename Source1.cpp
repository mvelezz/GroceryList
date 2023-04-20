#include "Header.h"
#include <iostream>
#include <fstream>
#include <map>


//Function to read the number of items from the item list
void frequencyCalc::optionOne() {
	std::ifstream inFS;
	std::string item;
	int wordFrq = 0;
	std::string currentWord;

	//std::cout << "Opening myfile.txt" << std::endl;

	inFS.open("myfile.txt");
	if (!inFS.is_open()) {
		std::cout << "Could not open file" << std::endl;
		//return 1;
	}
	std::cout << "Please input an item you wish to search for. ";
	std::cin >> item;

	while (!inFS.eof()) {
		inFS >> currentWord;
		if (!inFS.fail()) {
			if (currentWord == item) {
				wordFrq++;
			}
		}
	}

	std::cout << item << " " << wordFrq << std::endl;

	inFS.close();
}

//Function to print out all items and number of times that item occured in the list
void frequencyCalc::optionTwo() {
	std::ifstream inFS;
	std::string currentWord;

	//std::cout << "Opening myfile.txt" << std::endl;

	inFS.open("myfile.txt");
	if (!inFS.is_open()) {
		std::cout << "Could not open file" << std::endl;
		return;
	}

	std::map<std::string, int> m;
	while (inFS.eof() == false) {
		inFS >> currentWord;
		if (m.find(currentWord) == m.end()) {
			m[currentWord] = 1;
		}
		else {
			m[currentWord]++;
		}
	}
	std::map<std::string, int>::iterator it = m.begin();
	while (it != m.end()) {
		std::cout << it->first << " " << it->second << std::endl;
		it++;
	}
	inFS.close();

}

//function to print out a '*' to represent the number of items occured in the list
void frequencyCalc::optionThree() {
	std::ifstream inFS;
	std::string currentWord;

	//std::cout << "Opening myfile.txt" << std::endl;

	inFS.open("myfile.txt");
	if (!inFS.is_open()) {
		std::cout << "Could not open file" << std::endl;
		return;
	}

	std::map<std::string, int> m;
	while (inFS.eof() == false) {
		inFS >> currentWord;
		if (m.find(currentWord) == m.end()) {
			m[currentWord] = 1;
		}
		else {
			m[currentWord]++;
		}
	}
	for (auto item : m) {
		std::cout << item.first << " ";
		for (int i = 0; i < item.second; i++)
			std::cout << "*";
		std::cout << std::endl; // change line for next item
	}
	inFS.close();

}

//copy the txt file to a new data file
void frequencyCalc::copyToDat() {
	std::ifstream inFS;
	std::string currentWord;

	inFS.open("myfile.txt");
	if (!inFS.is_open()) {
		std::cout << "Could not open file" << std::endl;
		return;
	}

	std::map<std::string, int> m;
	while (inFS.eof() == false) {
		inFS >> currentWord;
		if (m.find(currentWord) == m.end()) {
			m[currentWord] = 1;
		}
		else {
			m[currentWord]++;
		}
	}
	inFS.close();

	std::ofstream outFS;
	outFS.open("myfile.dat");

	std::map<std::string, int>::iterator it = m.begin();
	while (it != m.end()) {
		outFS << it->first << " " << it->second << std::endl;
		it++;
	}

}