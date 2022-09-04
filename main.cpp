// =================================================================
//
// File: main.cpp
// Author: Arturo Diaz Lopez
// Date: 03/09/22
//
// =================================================================

#include <iostream>
#include <vector>
#include <fstream>
#include "header.h"
#include "search.h"
#include "bubble.h"
#include "selection.h"
#include "insertion.h"

using namespace std;

int main(int argc, char* argv[]) {

  ifstream inputFile;
	ofstream outputFile;

	int sN, sP;

	inputFile.open(argv[1]);
	outputFile.open(argv[2]);

	inputFile >> sN;
	vector<int>vectorN(sN);
	for(int n = 0; n < sN; n++) {
		inputFile >> vectorN[n];
	}
	
	vector<int> vectorN_1 = vectorN;
	vector<int> vectorN_2 = vectorN;

	int iS_n = insertionSort(vectorN_1);
	int bS_n = bubbleSort(vectorN_2);
	int sS_n = selectionSort(vectorN);

	outputFile << bS_n << " " << sS_n << " " << iS_n << endl << endl;

	inputFile >>  sP;
	pair<int,int> sS_P;
	pair<int,int> bS_P;

	int dP;

	for(int p = 0; p < sP; p++) {
		inputFile >> dP;
		sS_P = sequentialSearch(vectorN, dP);
		outputFile << sS_P.first << ' ' << sS_P.second << ' ';
		bS_P = binarySearch(vectorN, dP);
		outputFile << bS_P.second << endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}
