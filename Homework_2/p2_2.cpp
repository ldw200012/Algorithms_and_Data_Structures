#include <iostream>
#include <deque>
using namespace std;

int main(){

	deque <float> A;
	float elem;
	bool a = true;

	cout << "Enter Positive integers >>" << endl;

	while(true){
		cin >> elem;
		if(elem == 0.0){
			break;
		}else if(elem > 0.0){
			A.push_back(elem);
		}else{
			A.push_front(elem);
		}
	}

	deque <float>::iterator iterA;

	for(iterA = A.begin() ; iterA != A.end() ; iterA++){
		cout << *iterA << " ";
	}cout << endl;

	cout << endl;

	while(*(--iterA) > 0.0){
		if(iterA == A.begin()){
			iterA = A.insert(iterA,0.0);
			a = false;
			break;
		}
	}
	if(a){
		iterA++;
		iterA = A.insert(iterA,0.0);
	}

	for(iterA = A.begin() ; iterA != A.end() ; iterA++){
		cout << *iterA;
		if(iterA + 1 != A.end()){
			cout << "; ";
		}
	}cout << endl;

	return 0;
}