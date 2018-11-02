#include "HighScoreTable.h"
#include <fstream>
#include <sstream>


std::vector<HighScoreEntry> HighScoreTable::topNNScores(int topRows)
{
	// sort
	bubbleSortAscending();
	// return topRows
	std::vector<HighScoreEntry> topScores;

	// iterate through
	int idx = hsVector.size() - 1;
	for (int i = 0; i < topRows; i++) {
		if (idx < 0) {
			break;
		}
		topScores.push_back(hsVector[idx]);
		idx--;
	}

	// return
	return topScores;
}

bool HighScoreTable::pruneBottomNNScores(int bottomRows)
{
	if (hsVector.size() <= bottomRows) {
		return true;
	}

	// sort backwards
	bubbleSortDescending();

	for (int i = 0; i < bottomRows; i++) {
		// pop small end
		hsVector.pop_back();
	}

	return true; // ?
}

HighScoreTable::HighScoreTable()
{
}

HighScoreTable::HighScoreTable(std::string fileName)
{
	std::fstream file;
	std::string line;
	std::vector<HighScoreEntry> rtn;
	HighScoreEntry a;
	

	// open for reading
	file.open(fileName, std::ios::in);

	// if fail
	if (!file.is_open()) {
		std::cerr << "Error" << std::endl;
	}

	// while line is there
	while (std::getline(file, line)) {
		// separate line into parts
		
		std::string val;
		int category = 0;

		//  ADD EXCEPTIONS FOR FIRST LINE
		// BAD WAY TO DO IT I KNOW I'LL FIX LATER

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

void HighScoreTable::insertionSortAscending()
{
	for (int i = 0; i < hsVector.size(); i++) {
		for (int j = i; j > 0 && hsVector[j - 1].score > hsVector[j].score; j--) {
			HighScoreEntry temp = hsVector[j];
			hsVector[j] = hsVector[j - 1];
			hsVector[j - 1] = temp;
		}
	}
}

void HighScoreTable::insertionSortDescending()
{
	for (int i = 0; i < hsVector.size(); i++) {
		for (int j = i; j > 0 && hsVector[j - 1].score < hsVector[j].score; j--) {
			HighScoreEntry temp = hsVector[j];
			hsVector[j] = hsVector[j - 1];
			hsVector[j - 1] = temp;
		}
	}
}

void HighScoreTable::mergeSortDescending(int p, int r) {

	int q = (p + r) / 2;

	// terminate loop
	if (q >= r || p > q) {
		return;
	}

	// int p = 0;
	// int r = hsVector.size() - 1;
	mergeSortDescending(p, q);
	mergeSortDescending(q + 1, r);
	mergeDescending(p, q, r);
}

void HighScoreTable::mergeDescending(int p, int q, int r) {

	int leftEnd = q - p + 1;
	int rightEnd = r - q;

	HighScoreEntry * L = new HighScoreEntry[leftEnd];
	HighScoreEntry * R = new HighScoreEntry[rightEnd];

	for (int i = 0; i < leftEnd; i++) {
		L[i] = hsVector[p + i];
	}
	for (int j = 0; j < rightEnd; j++) {
		R[j] = hsVector[q + j + 1];
	}

	int i = 0;
	int j = 0;

	for (int k = p; k <= r; k++) {
		if (j >= rightEnd || (i < leftEnd and L[i].score >= R[j].score)) {
			hsVector[k] = L[i];
			i++;
		}
		else {
			hsVector[k] = R[j];
			j++;
		}
	}

	delete[] L;
	delete[] R;
}

void HighScoreTable::print()
{/*
	for (int i = 0; i < hsVector.size(); i++) {
		std::cout << hsVector[i].name << std::endl;
		std::cout << hsVector[i].score << std::endl;
		std::cout << hsVector[i].level << std::endl;
		std::cout << std::endl;
	}*/


	for (int i = 0; i < hsVector.size(); i++) {
		std::cout << hsVector[i].name << " ";
		std::cout << hsVector[i].score << " ";
		std::cout << hsVector[i].level << std::endl;
	}
}

void HighScoreTable::save(std::string fileName)
{
	std::fstream file;
	file.open(fileName, std::ios::out);

	if (file.fail()) {
		std::cerr << "Error" << std::endl;
		return;
	}

	// put data into file
	for (int i = 0; i < hsVector.size(); i++) {
		file << hsVector[i].name;
		file << ",";
		file << hsVector[i].score;
		file << ",";
		file << hsVector[i].level;
		file << "\n";
	}

	file.flush();
	file.close();
}
