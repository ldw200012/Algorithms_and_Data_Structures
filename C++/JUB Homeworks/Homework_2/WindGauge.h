#include <iostream>
#include <deque>
using namespace std;

class WindGauge{
public:
	WindGauge(int period = 12);
	void currentWindSpeed(int speed);
	int highest() const;
	int lowest() const;
	int average() const;
	// void printall();
private:
	int maxperiod;
	int sum;
	int max;
	int min;

	deque <int> timelist;
	deque <int>::iterator timeiter;
};