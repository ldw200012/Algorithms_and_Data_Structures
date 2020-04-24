#include <iostream>

template <class T>
int array_search(T somearr[], int size, T element){
	 for (int i = 0 ; i < size ; i++){
	 	if(somearr[i] == element){
	 		return i;
	 	}
	 }
	 	return -1;
}

class Complex{
private:
	int real;
	int imag;
public:
	Complex(int a, int b){
		real = a;
		imag = b;
	}
	~Complex(){
		std::cout << "Complex number Being Destructed" << std::endl;
	}
	bool operator==(Complex& another){
		if(another.real==real&&another.imag==imag){
			return true;
		}
		return false;
	}
};