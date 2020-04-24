//1st. BUILD_MAX_HEAP
//2nd. Swap 1st and last
//3rd. A.heapsize = A.heapsize - 1
//4th. 
#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
using namespace std;

int n = 0;
int printsize = 0;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void printall(int* A) {
	int i;
	for (i = 1; i <= printsize; i++) {
		cout << A[i] << " ";
	}cout << endl;
}

void REVERSED_MAX_HEAPIFY(int* A, int i) {
	bool again = false;
	// parent & sibling
	int parent = i / 2;
	//if parent >= 1 and A[parent] > A[i] then largest = parent;
	if (parent >= 1 && A[parent] > A[i]) {
		swap(A[i], A[parent]);
		again = true;
	}

	if (again) {
		REVERSED_MAX_HEAPIFY(A, parent);
	}
}

void MAX_HEAPIFY(int* A, int i) {
	int largest;
	bool again = false;
	// l = LEFT(i) & r = RIGHT(i)
	int l = 2 * i, r = 2 * i + 1;
	//if l <= A.heapsize and A[l] > A[i] then largest = l;
	if (l <= n && A[l] > A[i]) {
		largest = l;
	}
	else {
		largest = i;
	}
	//if r <= A.heapsize and A[r] > A[largest] then largest = r
	if (r <= n && A[r] > A[largest]) {
		largest = r;
	}
	if (largest != i) {
		swap(A[i], A[largest]);
		again = true;
	}

	if (again) {
		MAX_HEAPIFY(A, largest);
	}
}

void BUILD_MAX_HEAP(int* A) {
	int i;
	for (i = n / 2; i > 0; i--) {
		MAX_HEAPIFY(A, i);
	}
}

int FlowRootTillLeave(int* A, int i) {
	int l = 2 * i, r = 2 * i + 1;
	int larger;
	if (r <= n) {
		if (A[l] >= A[r]) {
			swap(A[l], A[i]);
			larger = l;
		}
		else {
			swap(A[r], A[i]);
			larger = r;
		}
		FlowRootTillLeave(A, larger);
	}
	else if (l <= n) {
		swap(A[l], A[i]);
		return l;
	}
	return i;
}

void Heapsort(int* A) {

	BUILD_MAX_HEAP(A);

	while (n > 1) {
		//exchange A[1] with A[n]
		swap(A[1], A[n]);

		//A.heapsize = A.heapsize - 1
		n--;

		//Flow till the end
		int currentLV = FlowRootTillLeave(A, 1);

		//Reversed_MAX_HEAPIFY
		REVERSED_MAX_HEAPIFY(A, currentLV);
	}

}

int main() {

	cin >> n;
	printsize = n;

	//Generator
	srand(time(NULL));
	int i;
	double sum = 0.0;
	int *A = new int[n + 1];

	for (int h = 0; h < 100; h++) {
		//Generator
		n = printsize;
		for (i = 1; i <= n; i++) { // do not use 0th index
			A[i] = rand() % 10;
		}

		//printall(A);
		chrono::system_clock::time_point start = chrono::system_clock::now();
		Heapsort(A);
		chrono::duration<double> ET = chrono::system_clock::now() - start;
		sum += ET.count()*1000000;
	}cout << sum/100.0 << endl;

	return 0;
}

