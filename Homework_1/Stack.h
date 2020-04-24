#include <iostream>

//Stack()
template<class T>
class Stack{
private:
	T *ptr;
	int size;
	int cursor = 0;
public:
	Stack(){
		size = 10;
		ptr = new T[size];
	}
	Stack(const Stack& another){
		size = another.size;
		cursor = another.cursor;
		ptr = new T[size];

		for(int i = 0; i < size ; i++){
			ptr[i] = another.ptr[i];
		}
	}
	Stack(int size){
		this->size = size;
		ptr = new T[size];
	}
	bool push(T element){
		if(cursor < size){
			ptr[cursor] = element;
			cursor++;
			return true;
		}
		return false;
	}
	bool pop(T& out){
		if(cursor == 0){
			return false;
		}
		cursor--;
		out = ptr[cursor];
		ptr[cursor] = 0.0f;
	}
	T back(){
		return ptr[cursor - 1];
	}
	int getNumEntries(){
		return cursor;
	}
	~Stack(){
		std::cout << "Stack being Destructed" << std::endl;
	}
};