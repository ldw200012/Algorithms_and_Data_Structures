#include "WindGauge.h"

int main(){
	WindGauge mygauge;

	mygauge.currentWindSpeed(15);
	mygauge.currentWindSpeed(16);
	mygauge.currentWindSpeed(12);
	mygauge.currentWindSpeed(15);
	mygauge.currentWindSpeed(15);

	// mygauge.printall();
	cout << mygauge.highest() << endl;
	cout << mygauge.lowest() << endl;
	cout << mygauge.average() << endl;

	mygauge.currentWindSpeed(16);
	mygauge.currentWindSpeed(17);
	mygauge.currentWindSpeed(16);
	mygauge.currentWindSpeed(16);
	mygauge.currentWindSpeed(20);
	mygauge.currentWindSpeed(17);
	mygauge.currentWindSpeed(16);
	mygauge.currentWindSpeed(15);
	mygauge.currentWindSpeed(16);
	mygauge.currentWindSpeed(20);
	// mygauge.currentWindSpeed(20);
	// mygauge.currentWindSpeed(20);
	// mygauge.currentWindSpeed(20);

	// mygauge.printall();
	cout << mygauge.highest() << endl;
	cout << mygauge.lowest() << endl;
	cout << mygauge.average() << endl;



	return 0;
}