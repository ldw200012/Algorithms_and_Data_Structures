#include "Stack.h"
using namespace std;

int main(){
	int i = 0;
	float j = 0.1;
	float outfloat = 0.0;

	Stack<int> intstack;
	Stack<float> floatstack(20);

	while(intstack.push(i)){i++;}
	while(floatstack.push(j)){j += 1.0;}

	Stack<float> floatstackcopy(floatstack);

	floatstack.pop(outfloat);
	floatstack.pop(outfloat);

	cout << intstack.back() << endl;
	cout << floatstack.back() << endl;
	cout << floatstackcopy.back() << endl;

	cout << intstack.getNumEntries() << endl;
	cout << floatstack.getNumEntries() << endl;	
	cout << floatstackcopy.getNumEntries() << endl;

	return 0;
}