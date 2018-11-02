#include "HighScoreTable.h"
#include <vector>
#include <time.h>
#include <stdlib.h>


// ERROR HANDLING FOR TOPSCORES < NUMBER OF SCORES

// ascending
void merge(int A[], int p, int q, int r) {

	int leftEnd = q - p + 1;
	int rightEnd = r - q;

	int * L = new int[leftEnd];
	int * R = new int[rightEnd];

	for (int i = 0; i < leftEnd; i++) {
		L[i] = A[p + i];
	}
	for (int j = 0; j < rightEnd; j++) {
		R[j] = A[q + j + 1];
	}

	int i = 0;
	int j = 0;

	for (int k = p; k <= r; k++) {
		if (j >= rightEnd || (i < leftEnd and L[i] <= R[j])) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
	}

	delete[] L;
	delete[] R;
}

void mergeSort(int arr[], int p, int r) {
	// int q = 0;
	if (p < r) {
		int q = (p + r) / 2;
		mergeSort(arr, p, q);
		mergeSort(arr, q + 1, r);
		merge(arr, p, q, r);
	}
}


int main() {
	
	//Instantiate and initialize the whole highscore table
	HighScoreTable hst("highscores.txt");

	/*
	//retrieve the top 10 scores
	std::vector<HighScoreEntry> topScores = hst.topNNScores(10);
	//todo: cycle through the scores and output them
	for (int i = 0; i < topScores.size(); i++) {
		std::cout << topScores[i].name << std::endl;
		std::cout << topScores[i].score << std::endl;
		std::cout << topScores[i].level << std::endl;
		std::cout << std::endl;
	}

	//prune the bottom 3 scores from the table
	hst.pruneBottomNNScores(3);

	topScores = hst.topNNScores(10);

	std::cout << std::endl;
	for (int i = 0; i < topScores.size(); i++) {
		std::cout << topScores[i].name << std::endl;
		std::cout << topScores[i].score << std::endl;
		std::cout << topScores[i].level << std::endl;
		std::cout << std::endl;
	}

	hst.save("saveData.txt");

	// std::cout << std::endl;
	// hst.print();

	HighScoreTable test2("scores2.txt");
	std::cout << "Original" << std::endl;
	test2.print();
	std::cout << "Ascending" << std::endl;
	test2.insertionSortAscending();
	test2.print();
	std::cout << "Descending" << std::endl;
	test2.insertionSortDescending();
	test2.print();
	*/

	
	srand(time(NULL));

	/*
	const int nums = 20;

	int arr[nums];
	// add to arr
	for (int i = 0; i < nums; i++) {
		arr[i] = rand() % 100; // 0 - 99
	}

	// print
	for (int i = 0; i < nums; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	// sort
	mergeSort(arr, 0, nums-1);

	// print
	for (int i = 0; i < nums; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	*/

	hst.print();
	hst.mergeSortDescending(0, hst.hsVector.size() - 1);
	std::cout << std::endl;
	hst.print();

	system("pause");

	return 0;
}