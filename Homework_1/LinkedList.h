//Constructors
//Destructor
//Return first and last element 
//Add new element at the front 
//Add new element at the end of the list
//Return amount of elements

#include <iostream>

template <class T, int initialsize = 10>
class Mydeque{
private:
	T* somearr;
	int maxsize;
	int cursor;
public:
	Mydeque(){
		somearr = new T[initialsize];
		maxsize = initialsize;
		cursor = 0;
	}
	~Mydeque(){
		delete[] somearr;
		std::cout << "Deque being Destructed" << std::endl;
	}
	T firstelement(){
		return somearr[0];
	}
	T lastelement(){
		return somearr[cursor-1];
	}
	void addatfront(T another){
		if(cursor < maxsize){
			for(int i = cursor ; i > 0 ; i--){
				somearr[i] = somearr[i-1];
			}
			somearr[0] = another;
			cursor++;
		}
	}
	void addatend(T another){
		if(cursor != maxsize){
			somearr[cursor] = another;
			cursor++;
		}
	}
	int amount(){
		return cursor;
	}
	// int printall(){
	// 	for (int n = 0 ; n < cursor ; n++){
	// 		std::cout << somearr[n] << std::endl;
	// 	}
	// }
};
