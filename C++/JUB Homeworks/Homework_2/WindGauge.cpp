#include "WindGauge.h"

WindGauge::WindGauge(int period){
	maxperiod = period;
	sum = 0;
	max = 0;
	min = 0;
}

void WindGauge::currentWindSpeed(int speed){
	timeiter = timelist.begin();
	// Add element & Sum
	if(timelist.size() >= maxperiod){
		sum -= *timeiter;
		timeiter = timelist.erase(timeiter);
	}
	timelist.push_back(speed);
	sum += speed;


	timeiter = timelist.begin();
	max = *timeiter;
	for(timeiter ; timeiter != timelist.end() ; timeiter++){
		if(*timeiter > max){
			max = *timeiter;
		}
	}


	timeiter = timelist.begin();
	min = *timeiter;
	for(timeiter = timelist.begin() ; timeiter != timelist.end() ; timeiter++){
		if(*timeiter < min){
			min = *timeiter;
		}
	}

}
int WindGauge::highest() const{
	return max;
}

int WindGauge::lowest() const{
	return min;
}

int WindGauge::average() const{
	return sum/timelist.size();
}

// void WindGauge::printall(){
// 	for(timeiter = timelist.begin() ; timeiter != timelist.end() ; timeiter++){
// 		cout << *timeiter << " ";
// 	}cout << endl;
// }