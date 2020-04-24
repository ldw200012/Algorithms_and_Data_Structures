#include "LinkedList.h"
using namespace std;

int main(){
	Mydeque<int> myInts;
	Mydeque<int, 20> myInts2;
	Mydeque<double> myDoubles;
	Mydeque<char> myChars;
	int i;

	//fill all the 10 storages
	for(i = 0 ; i < 5 ; i++){
		myInts.addatend(i+1);
	}
	myInts.addatfront(97);
	myInts.addatfront(32);
	myInts.addatfront(19);
	myInts.addatfront(10000);
	myInts.addatend(100);
	//next two steps should not work
	myInts.addatfront(222);
	myInts.addatend(222);


	//fill all the 20 storages
	for(i = 0 ; i < 18 ; i++){
		myInts2.addatend(i+1);
	}
	myInts2.addatfront(77);
	myInts2.addatend(77);
	//next two steps should not work
	myInts2.addatfront(222);
	myInts2.addatend(222);


	//fill all the 10 storages
	for(i = 0 ; i < 8 ; i++){
		myDoubles.addatend(i+0.1);
	}
	myDoubles.addatfront(20.6);


	//fill all the 10 storages
	for(i = 65 ; i < 73 ; i++){
		myChars.addatend(i+1);
	}
	myChars.addatfront('Z');
	myChars.addatfront('Y');
	//next two steps should not work
	myChars.addatfront('X');
	myChars.addatend('W');

	// myInts.printall();
	// myInts2.printall();
	// myDoubles.printall();
	// myChars.printall();

	cout << "myInts::firstelement() --> " << myInts.firstelement() << endl
		<< "myInts::lastelement() --> " << myInts.lastelement() << endl << "myInts::amount() --> " << myInts.amount() << endl;

	cout << "myInts2::firstelement() --> " << myInts2.firstelement() << endl
		<< "myInts2::lastelement() --> " << myInts2.lastelement() << endl << "myInts2::amount() --> " << myInts2.amount() << endl;

	cout << "myDoubles::firstelement() --> " << myDoubles.firstelement() << endl
		<< "myDoubles::lastelement() --> " << myDoubles.lastelement() << endl << "myDoubles::amount() --> " << myDoubles.amount() << endl;

	cout << "myChars::firstelement() --> " << myChars.firstelement() << endl
		<< "myChars::lastelement() --> " << myChars.lastelement() << endl << "myChars::amount() --> " << myChars.amount() << endl;

	return 0;
}