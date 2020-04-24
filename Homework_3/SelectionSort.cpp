#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
using namespace std;

// Selection-Sort(A,n)
int n = 13;

void MakeRandom(int* A) {					// Random Sequence
	srand((unsigned int)time(NULL));

	int m = n;
	while (--m > -1) {
		A[m] = rand() % n;
	}
}

void MakeWorst(int* A) {					// Case A
	int idx = 0;
	for (int i = n / 2 ; i < n; i++) {
		A[idx] = i;
		idx += 2;
	}
	idx = 1;
	for (int i = 0; i < n / 2; i++) {
		A[idx] = i;
		idx += 2;
	}
}

void MakeBest(int* A) {						// Case B
	for (int i = 0; i < n; i++) {
		A[i] = i;
	}
}

void printArray(int* A) {
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}cout << endl;
}

int main() {

	int* A = new int[n];								// Create an empty array with size n

	// MakeRandom(A);								// Put the elements randomly in array A
	MakeWorst(A);									// Put the elements in zig-zag order
	// MakeBest(A);									// Put the elements in ascending order

	printArray(A);								// Preview our Randomly made array by std output

	int min, minindex;							// Create the variables to store the Min value and its index at every iteration

	chrono::system_clock::time_point start = chrono::system_clock::now();

	for (int j = 0; j < n; j++) {				// Selection Sort in progress
		min = A[j];
		minindex = j;
		for (int i = j + 1; i < n; i++) {
			if (A[i] < min) {
				min = A[i];
				minindex = i;
			}
		}
		A[minindex] = A[j];
		A[j] = min;
	}

	chrono::system_clock::time_point stop = chrono::system_clock::now();
	chrono::duration<double> elapsed = stop - start;

	printArray(A);								// Check the validity of our Selection Sort Algorithm
	cout << elapsed.count() << " seconds" << endl;

	delete []A;

	return 0;
}
