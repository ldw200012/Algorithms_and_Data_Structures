#include <iostream>
using namespace std;

class Node {
public:
	int key;
	int value;
	//Constructor
	Node(int key, int value) {
		this->key = key;
		this->value = value;
	}
};

class HashTable {
private:
	Node** arr;
	int maxsize;
	int currentsize;
public:
	//Default Constructor
	HashTable(int ms = 10) {
		maxsize = ms;
		currentsize = 0;
		arr = new Node * [maxsize];

		int i;
		for (i = 0; i < maxsize; i++) {
			arr[i] = NULL;
		}
	}
	//Return Hashcode of the Node with 'key'l
	Node* hashCode(int key) {
		int i, idx;
		for (i = 0; i < maxsize; i++) {
			idx = hashfunction(key, i);
			if (arr[idx] == NULL) {
				cout << "No Hashcode Found for the Key_1";
				// The Node with the key is not yet allocated
				return NULL;
			}
			else if (arr[idx]->key == key) {
				return arr[idx];
			}
		}
		cout << "No Hashcode Found for the Key_2";
		// The Node with the key couldn't be allocated for the Hashtable was already full
		return NULL;
	}

	int hashfunction(int key, int i) {
		return (hashprimefunction(key) + i) % maxsize;
	}

	int hashprimefunction(int key) {
		return key / 10;
	}

	void insertNode(int key, int value) {
		int i, idx;

		if (currentsize == maxsize) {
			cout << "Hash Table is Full " << endl;
		}
		else {
			for (i = 0; i < maxsize; i++) {
				//cout << "i value : " << i << " ";
				idx = hashfunction(key, i);
				//cout << "idx value : " << idx << endl;
				if (arr[idx]==NULL) {
					cout << idx << endl;
					arr[idx] = new Node(key, value);
					currentsize++;
					break;
				}
			}
		}
	}

	int get(int key) {
		int i, idx;
		for (i = 0; i < maxsize; i++) {
			idx = hashfunction(key, i);
			if (arr[idx] == NULL) {
				cout << "No Hashcode, so no value can be Found for the Key_1";
				// The Node with the key is not yet allocated
				return -1;
			}
			else if (arr[idx]->key == key) {
				return arr[idx]->value;
			}
		}
		cout << "No Hashcode, so no value can be Found for the Key_2";
		// The Node with the key couldn't be allocated for the Hashtable was already full
		return -1;
	}

	bool isEmpty() {
		if (this->currentsize < 1) {
			return true;
		}
		else {
			return false;
		}
	}
};
/*
int main() {
	// 13, 25, 32, 73, 2, 102, 43
	HashTable myhashtable;

	cout << myhashtable.isEmpty() << endl; // 1 expected

	myhashtable.insertNode(12, 1200);
	cout << myhashtable.isEmpty() << endl; // 0 expected
	myhashtable.insertNode(12, 1200);
	myhashtable.insertNode(12, 1200);
	myhashtable.insertNode(12, 1200);
	myhashtable.insertNode(12, 1200);
	myhashtable.insertNode(12, 1200);
	myhashtable.insertNode(12, 1200);
	myhashtable.insertNode(20, 4780);
	myhashtable.insertNode(12, 1200);
	myhashtable.insertNode(12, 1200);
	myhashtable.insertNode(12, 1200); // Hash Table should be full here
	myhashtable.insertNode(34, 1100); // Hash Table should be full here

	cout << myhashtable.isEmpty() << endl; // 0 expected

	cout << myhashtable.get(3) << endl;
	cout << myhashtable.get(34) << endl;
	cout << myhashtable.get(12) << endl;
	cout << myhashtable.get(20) << endl;

	cout << myhashtable.hashCode(3) << endl;
	cout << myhashtable.hashCode(34) << endl;
	cout << myhashtable.hashCode(12) << endl;
	cout << myhashtable.hashCode(20) << endl;
}
*/

int main() {
	// 13, 25, 32, 73, 2, 102, 43
	HashTable myhashtable;

	cout << myhashtable.isEmpty() << endl; // 1 expected

	myhashtable.insertNode(13, 1300);
	myhashtable.insertNode(25, 2500);
	myhashtable.insertNode(32, 3200);
	myhashtable.insertNode(73, 7300);
	myhashtable.insertNode(2, 200);
	myhashtable.insertNode(102, 10200);
	myhashtable.insertNode(43, 4300);

	cout << myhashtable.isEmpty() << endl; // 1 expected
	
	cout << myhashtable.get(13) << endl;
	cout << myhashtable.get(25) << endl;
	cout << myhashtable.get(32) << endl;//
	cout << myhashtable.get(73) << endl;
	cout << myhashtable.get(2) << endl;
	cout << myhashtable.get(102) << endl;//
	cout << myhashtable.get(43) << endl;//

	cout << myhashtable.hashCode(13) << endl;
	cout << myhashtable.hashCode(25) << endl;
	cout << myhashtable.hashCode(32) << endl;
	cout << myhashtable.hashCode(73) << endl;
	cout << myhashtable.hashCode(2) << endl;
	cout << myhashtable.hashCode(43) << endl;
	cout << myhashtable.hashCode(102) << endl;

}