//============================================================================
// Name        : CS202HW3.cpp
// Author      : Mert Aytore
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "heap.h"
using namespace std;

int main(int argc, char** argv) {
	if (argc == 3) {

		int numberOfElements = 0;

		ifstream inputFile;
		inputFile.open("data1.txt");

		//Calculates number of elemets
		string number;
		while (inputFile >> number) {
			numberOfElements++;
		}

		//Creates a heap whose size is equal to number of elements in the file
		heap maxHeap(numberOfElements);

		//Turns beginning of the file
		inputFile.clear();
		inputFile.seekg(0);

		//Inserts each numbers in the file to the heap
		while (inputFile >> number) {
			maxHeap.insert(atoi(number.c_str()));
		}

		inputFile.close();

		ofstream outputFile;
		outputFile.open("out2.txt");

		// Prints number of elements and number of comparisons
		cout << "n = " << numberOfElements << ", Number of comparisons = " << maxHeap.getComparisonsCount() << endl;

		// Writes the numbers in the input file in descending order to specified file
		for (int i = 0; i < numberOfElements; i++) {
			outputFile << maxHeap.popMaximum() << "\n";
		}

		outputFile.close();

	}

	else
	{
		cout << "Input number mismatch" << endl;
	}
	return 0;
}
