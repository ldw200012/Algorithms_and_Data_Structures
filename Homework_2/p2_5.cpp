#include <iostream>
#include <stdlib.h>
#include <map>
using namespace std;

class myComparison{
public:
	bool operator()(int a, int b) const{
		return (a < b);
	}

};


int main(){

	map<int, int, myComparison> numkeys;

	while(numkeys.size() <= 6){
		int n = rand() % 49 + 1;
		numkeys[n] = 0;
	}

	map <int, int, myComparison>::iterator myiter;
	for(myiter = numkeys.begin() ; myiter != numkeys.end() ; myiter++){
		cout << (*myiter).first << " ";
	}cout << endl;
	

	return 0;
}