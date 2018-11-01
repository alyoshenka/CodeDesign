#include "HighScoreTable.h"
#include <vector>

// ERROR HANDLING FOR TOPSCORES < NUMBER OF SCORES

int main() {
	//Instantiate and initialize the whole highscore table
	HighScoreTable hst("highscores.txt");

	//retrieve the top 10 scores
	std::vector<HighScoreEntry> topScores = hst.topNNScores(10);
	//todo: cycle through the scores and output them
	for (int i = 0; i < 10; i++) {
		std::cout << topScores[i].name << std::endl;
		std::cout << topScores[i].score << std::endl;
		std::cout << topScores[i].level << std::endl;
		// std::cout << std::endl;
	}

	//prune the bottom 3 scores from the table
	hst.pruneBottomNNScores(3);

	std::cout << std::endl;
	hst.print();

	system("pause");

	return 0;
}