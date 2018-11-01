#include "HighScoreTable.h"
#include <fstream>


std::vector<HighScoreEntry> HighScoreTable::topNNScores(int topRows)
{
	// sort
	bubbleSortAscending();
	// return topRows
	std::vector<HighScoreEntry> topScores;

	// iterate through
	int idx = hsVector.size() - 1;
	for (int i = 0; i < topRows; i++) {
		topScores.push_back(hsVector[idx]);
		idx--;
	}

	// return
	return topScores;
}

bool HighScoreTable::pruneBottomNNScores(int bottomRows)
{
	// sort
	// bubbleSort();

	// sort backwards
	bubbleSortDescending();

	for (int i = 0; i < bottomRows; i++) {
		// pop small end
		hsVector.pop_back();
	}
	return false; // ?
}

HighScoreTable::HighScoreTable()
{
}

HighScoreTable::HighScoreTable(std::string fileName)
{
	std::fstream file;
	// open for reading
	file.open(fileName, std::ios_base::in);

	// if fail
	if (!file.is_open()) {
		std::cerr << "Error" << std::endl;
	}

	HighScoreEntry a;

	// load data by line 
	std::string line;
	// while line is there
	while (std::getline(file, line)) {
		// separate line into parts
		
		std::string val;
		int category = 0;

		//  ADD EXCEPTIONS FOR FIRST LINE

		// iterate through line
		for (int i = 0; i < line.length(); i++) {
			// if comma
			if (line[i] == 44) {
				// change value
				switch (category) {
				case 0:
					a.name = val;
					break;
				case 1:
					a.score = std::stoi(val);
					break;
				case 2:
					a.level = std::stoi(val); // FIX THIS
					break;
				default:
					// no clue
					break;
				}

				// clear val
				val = "";
				// move to next category
				category++;
			}
			else {
				// add value
				val += line[i];
			}
		}

		a.level = std::stoi(val);

		// add a to vector
		hsVector.push_back(a);
	}

	// close file
	file.close();
}


HighScoreTable::~HighScoreTable()
{
}

void HighScoreTable::bubbleSortAscending()
{
	for (int i = 0; i < hsVector.size(); i++) {
		// int n = i;
		for (int n = 0; n < hsVector.size() - i - 1; n++) {
			if (hsVector[n].score > hsVector[n + 1].score) { 
				// swap
				HighScoreEntry temp = hsVector[n+1];
				hsVector[n+1] = hsVector[n];
				hsVector[n] = temp;
			}
		}
	}
}

void HighScoreTable::bubbleSortDescending()
{
	for (int i = 0; i < hsVector.size(); i++) {
		// int n = i;
		for (int n = 0; n < hsVector.size() - i - 1; n++) {
			if (hsVector[n].score < hsVector[n + 1].score) {
				// swap
				HighScoreEntry temp = hsVector[n + 1];
				hsVector[n + 1] = hsVector[n];
				hsVector[n] = temp;
			}
		}
	}
}

void HighScoreTable::print()
{
	for (int i = 0; i < hsVector.size(); i++) {
		std::cout << hsVector[i].name << std::endl;
		std::cout << hsVector[i].score << std::endl;
		std::cout << hsVector[i].level << std::endl;
		std::cout << std::endl;
	}
}
