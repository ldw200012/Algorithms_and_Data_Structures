#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <cstdio>
using namespace std;

int main(){

	map <string, string> BDList;
	map <string, string>::iterator myiter;
	ifstream myfile;
	myfile.open("data.txt");

	string firstname, lastname, birthday;
	if(myfile.is_open()){
		while(!myfile.eof()){
			myfile >> firstname >> lastname >> birthday;
			BDList[firstname+" "+lastname] = birthday;
		}
	}
	
	string query;
	getline(cin, query);

	for(myiter = BDList.begin() ; myiter != BDList.end() ; myiter++){
		if((*myiter).first == query){
			cout << (*myiter).second << endl;
			break;
		}
	}
	if(myiter == BDList.end()){
		cout << "Name not found!" << endl;
	}

	return 0;
}