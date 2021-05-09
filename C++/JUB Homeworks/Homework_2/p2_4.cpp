#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	vector <int> myvector;
	
	//fills a vector with the integer values from 1 to 30
	for(int i = 1 ; i <= 30 ; i++){
		myvector.push_back(i);
	}

	//add a value 5 at the end of the vector
	myvector.push_back(5);

	//reverse the vector
	int n = myvector.size();
	reverse(myvector.begin(), myvector.end());

	//print the content of the vector on the standard output using an iterator
	vector <int>::iterator myiter = myvector.begin();
	for(myiter ; myiter != myvector.end() ; myiter++){
		cout << *myiter << " ";
	}cout << endl;

	//replace all '5' into '129'
	for(myiter = myvector.begin() ; myiter != myvector.end() ; myiter++){
		if(*myiter == 5){
			replace(myvector.begin(), myvector.end(), 5, 129);
		}
	}

	//print again on the standard output
	for(myiter = myvector.begin() ; myiter != myvector.end() ; myiter++){
		cout << *myiter << " ";
	}cout << endl;



	return 0;
}
