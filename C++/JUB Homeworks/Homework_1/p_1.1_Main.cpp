#include "p_1.1_Header.h"
#include <string>
using namespace std;

int size = 10;

int main(){
	int numarr[10] = {0,1,2,3,4,5,6,7,8,9};
	double dbarr[10] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.1};
	char chrarr[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	Complex comarr[10] = {Complex(1,4), Complex(7,2), Complex(3,-2), Complex(-1,1), Complex(5,0),
		Complex(0,1), Complex(-9,4), Complex(1,-2), Complex(-3,-6), Complex(9,4)};

	cout << array_search(numarr, size, 8) << endl;
	cout << array_search(dbarr, size, 0.3) << endl;
	cout << array_search(dbarr, size, 1.0) << endl;
	cout << array_search(chrarr, size, 'f') << endl;
	cout << array_search(comarr, size, Complex(3,-2)) << endl;

	return 0;
}