#include "Access.h"
using namespace std;

inline int DoorOpen(Access &EntranceKeys){
	int user;

	while(true){
		cout << "Enter the Entrance Key >> ";
		cin >> user;

		if(EntranceKeys.isactive(user)){
			cout << "Door Opened !" << endl;
			break;
		}else{
			cout << "Try again .." << endl;
		}
	}

	return user;
}

int main(){

	Access EntranceKeys;

	EntranceKeys.activate(1234);
	EntranceKeys.activate(9999);
	EntranceKeys.activate(9876);

	EntranceKeys.deactivate(DoorOpen(EntranceKeys));
	EntranceKeys.deactivate(9999);
	EntranceKeys.activate(1111);

	EntranceKeys.deactivate(DoorOpen(EntranceKeys));

	return 0;
}
