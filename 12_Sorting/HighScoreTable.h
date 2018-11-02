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
	// true if rowCount > bottomRows
	bool pruneBottomNNScores(int bottomRows);

	HighScoreTable(); // HAS NOT BEEN IMPLEMENTED YET
	HighScoreTable(std::string fileName);
	~HighScoreTable();

	void bubbleSortAscending();
	void bubbleSortDescending();
	void insertionSortAscending();
	void insertionSortDescending();
	// def values: 0, hsVector.size() - 1
	void mergeSortDescending(int p, int r);
	void mergeDescending(int p, int q, int r);
	void print();
	void save(std::string fileName);
};
