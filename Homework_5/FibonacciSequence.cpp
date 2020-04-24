#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;

unsigned int NaiveRecursive(int n) {
	if (n < 2) {
		return n;
	}
	else {
		return NaiveRecursive(n - 2) + NaiveRecursive(n - 1);
	}
}

unsigned int BottomUp(int n) {
	int first = 0, second = 1, result = 0;
	if (n < 2) {
		return n;
	}
	while (n > 1) {
		result = first + second;
		first = second;
		second = result;
		n--;
	}
	return result;
}

double PowerRecurse(double base, int n) {
	if (n > 0) {
		return (base * PowerRecurse(base, n - 1));
	}else {
		return 1;
	}
}

unsigned int ClosedForm(int n) { // Using "Power of a number" recursion
	if (n < 2) {
		return n;
	}
	else if (n == 2) {
		return 1;
	}
	else {
		return round(PowerRecurse(((1 + sqrt(5)) / 2), n) / sqrt(5));
		//The slide says we should round the result to next integer, but in won't work.
	}
}

unsigned int MatrixRep(int n) {
	unsigned int matrix[2][2];
	unsigned int t1 = 1, t2 = 1, t3 = 1, t4 = 0;

	if (n < 2) {
		return n;
	}
	else {
		for (int i = 1; i < n; i++) {
			matrix[0][0] = t1;
			matrix[0][1] = t2;
			matrix[1][0] = t3;
			matrix[1][1] = t4;

			t1 = matrix[0][0] + matrix[1][0];
			t2 = matrix[0][1] + matrix[1][1];
			t3 = matrix[0][0];
			t4 = matrix[0][1];
		}
		return t2;
	}
}

int main() {
	unsigned int m;
	cout << "Value of m >> ";
	cin >> m;

	////Execution Time Measurement
	//unsigned int n, result = 0;
	//for (n = 0; n < 81; n++) {
	//	chrono::system_clock::time_point start = chrono::system_clock::now();
	//	//result = NaiveRecursive(n);
	//	//result = BottomUp(n);
	//	result = ClosedForm(n);
	//	//result = MatrixRep(n);
	//	chrono::duration<double> ET = chrono::system_clock::now() - start;

	//	cout << "Execution Time (ms) : " << ET.count() * pow(10, 6) << endl;
	//}

	cout << "Naive Recursive : " << NaiveRecursive(m) << endl;
	cout << "Bottom Up : " << BottomUp(m) << endl;
	cout << "Closed Form : " << ClosedForm(m) << endl;
	cout << "Matrix Representation : " << MatrixRep(m) << endl;

	return 0;
}