#include "Access2.h"
using namespace std;

inline int DoorOpen(Access &myAccess, int reqlev){
 	unsigned int user;

 	while(true){
		cout << "Enter the Entrance Key >> ";
		cin >> user;

		if(myAccess.isactive(user, reqlev)){
			cout << "Door Opened !" << endl;
			break;
		}else{
			cout << "Try again .." << endl;
		}
	}

	return user;
}

int main(){
	Access myAccess;

	myAccess.activate(1234,1);
	myAccess.activate(9999,5);
	myAccess.activate(9876,9);

	myAccess.deactivate(DoorOpen(myAccess, 5));
	
	myAccess.activate(9999, 8);
	myAccess.activate(1111, 7);

	myAccess.deactivate(DoorOpen(myAccess, 7));

	return 0;
}
