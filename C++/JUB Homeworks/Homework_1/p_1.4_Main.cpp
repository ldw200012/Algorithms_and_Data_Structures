#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	vector<string> strvec;
	string word;
	string end = "END";

	while(1){
		cin >> word;
		if(word.compare(end) == 0){
			break;
		}
			strvec.push_back(word);
	}

	for(int i = 0 ; i < strvec.size() ; i++){
		cout << strvec[i] << " ";
	}cout << endl;

	vector<string>::const_iterator where;
	for(where = strvec.begin() ; where != strvec.end() ; where++){
		cout << *where;
		if(where + 1 != strvec.end()){
			cout << ", ";
		}
	}cout << endl;

	return 0;
}