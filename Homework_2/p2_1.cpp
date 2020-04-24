#include <iostream>
#include <list>
#include <fstream>
using namespace std;

int main(){

	list <int> A, B;
	int elem;
	ofstream outfile;

	cout << "Enter Positive Integers  >>" << endl;
	while(true){
		cin >> elem;
		if(elem <= 0){
			break;
		}
		A.push_back(elem);
		B.push_front(elem);
	}

	list <int>::iterator iterA, iterB;

	for(iterA = A.begin() ; iterA != A.end() ; iterA++){
		cout << *iterA << " ";
	}cout << endl;

	outfile.open("listB.txt");
	for(iterB = B.begin() ; iterB != B.end() ; iterB++){
		outfile << *iterB << " ";
	}outfile << endl;

	cout << endl;
	A.merge(B);

	for(iterA = A.begin() ; iterA != A.end() ; iterA++){
		cout << *iterA << " ";
	}cout << endl;

	outfile.close();

	return 0;
}