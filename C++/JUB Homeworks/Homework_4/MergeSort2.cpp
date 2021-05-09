#include <iostream>
#include <random>
#include <chrono>
#include <cstdlib>
using namespace std;

int n = 100000, k = 2;

void Merge(int* numarr, int start, int mid, int end) {
	int size = end - start, size1 = mid - start, size2 = end - mid, k;

	int* numarr1 = new int[size1];
	for (k = 0; k < size1; k++) {
		numarr1[k] = numarr[start + k];
	}
	int* numarr2 = new int[size2];
	for (k = 0; k < size2; k++) {
		numarr2[k] = numarr[mid + k];
	}

	int idx, t1 = 0, t2 = 0, i;

	for (int i = start; i < end; i++) {
		numarr[i] = 0;
	}
	
	for (i = start; i < end; i++) {
		if (t1 < size1 && t2 < size2) {
			numarr[i] = numarr1[t1] <= numarr2[t2] ? numarr1[t1++] : numarr2[t2++];
		}
		else if (t1 < size1 && t2 >= size2) {
			numarr[i] = numarr1[t1++];
		}
		else if (t2 < size2 && t1 >= size1) {
			numarr[i] = numarr2[t2++];
		}
	}

	delete numarr1;
	delete numarr2;
}

void InsertionSort(int* numarr, int start, int end) {
	int i, j, temp;
	for (i = start+1; i < end; i++) {
		temp = numarr[i];
		for (j = i - 1; numarr[j] > temp && j >= start; j--) {
			numarr[j + 1] = numarr[j];
		}
		numarr[++j] = temp;
	}
}

void MergeSort(int* numarr, int start, int end){
	int size = end-start, mid = (start+end)/2;

	if ((size / 2) > k) {
		MergeSort(numarr, start, mid);
	}
	if ((size - (size / 2)) > k) {
		MergeSort(numarr, mid, end);
	}
	
	//InsertionSort
	InsertionSort(numarr, start, mid);
	InsertionSort(numarr, mid, end);

	//Merge
	InsertionSort(numarr, start, end);
}

int main() {

	//Make an Array
	int* numarr = new int[n];

	//random
	//srand(time(NULL));
	//int i;
	//for (i = 0; i < n; i++) {
	//	numarr[i] = rand() % 100;
	//}

	//best_case
	int i;
	for (i = 0; i < n; i++) {
		numarr[i] = i;
	}

	//worst_case
	//int i;
	//for (i = 0; i < n; i++) {
	//	numarr[i] = n - 1;
	//}

	//for (i = 0; i < n; i++) {
	//	cout << numarr[i] << " ";
	//}cout << endl;

	chrono::system_clock::time_point start = chrono::system_clock::now();
	//MergeSort
	MergeSort(numarr, 0, n);
	chrono::duration<double> ET = chrono::system_clock::now() - start;
	cout << ET.count() << endl;

	//for (i = 0; i < n; i++) {
	//	cout << numarr[i] << " ";
	//}cout << endl;

	delete[] numarr;
	return 0;
}