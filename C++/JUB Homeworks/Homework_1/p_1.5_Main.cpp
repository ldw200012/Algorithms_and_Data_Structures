#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<string> strvec;
	string word, temp;
	string end = "END";

	//1.
	while(1){
		getline(cin, word);
		if(word.compare(end) == 0){
			break;
		}
		//2.
		strvec.push_back(word);
	}

	int vectorsize = strvec.size();

	//3.
	if((strvec[1].compare("")!=0) && (strvec[4].compare("")!=0)){
		temp = strvec[1];
		strvec[1] = strvec[4];
		strvec[4] = temp;
	}else{
		((strvec[1].compare("")==0) &&(strvec[4].compare("")==0)) ? (cout << "Both do not Exist" << endl) : ((strvec[1].compare("")!=0) ? (cout << "5th does not Exist" << endl) : (cout << "2nd does not Exist" << endl));
	}

	//4.
	strvec[vectorsize-1] = "???";

	//5.
	for(int i = 0 ; i < vectorsize ; i++){
		cout << strvec[i];
		if(i+1 != vectorsize){
			cout << ", ";
		}
	}cout << endl;

	//6.
	vector<string>::iterator where;
	for(where = strvec.begin() ; where != strvec.end() ; where++){
		cout << *where;
		if(where + 1 != strvec.end()){
			cout << "; ";
		}
	}cout << endl;

	//7.
	for(where = strvec.end()-1 ; where != strvec.begin() ; where--){
		cout << *where << " ";
	}cout << *where << endl;

	return 0;
}