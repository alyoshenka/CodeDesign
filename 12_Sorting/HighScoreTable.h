// highscoretable.h
#pragma once
#include "HighScoreEntry.h"
#include <vector>
#include <string>

class HighScoreTable
{
public:
	std::vector<HighScoreEntry> hsVector;
	std::vector<HighScoreEntry> topNNScores(int topRows);
	bool pruneBottomNNScores(int bottomRows);

	HighScoreTable();
	HighScoreTable(std::string fileName);
	~HighScoreTable();

	void bubbleSortAscending();
	void bubbleSortDescending();
	void print();
};
