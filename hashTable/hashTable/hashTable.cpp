#include "stdafx.h"
#include <iostream>
class Node{
public:
	int element;
	Node *next;
	int size = 0;
	Node(){
		element = -1;
		next = NULL;
		size = 0;
	}
	Node(int number){
		element = number;
	}

	void print()
	{
		Node* temp = this;
		while (temp){
			std::cout << temp->element << "\t";
			temp = temp->next;
		}
		std::cout << std::endl;
	}
	void sort(){

	}
};
class HashTable{
	Node *array;
public:
	HashTable(){
		array = new Node[10];
	}
	void chaining(int newNumber){
		int index = hash(newNumber, 10);
		if (array[index].element == NULL){
			array[index].element = newNumber;
		}
		else{
			Node* newNode = new Node(newNumber);
			Node* temp = &(array[index]);
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = newNode;
			array[index].sort();
		}
	}
	void print(){
		for (int i = 0; i < 10; i++){
			array[i].print();
		}
	}
	~HashTable(){
		delete[] array;
	}
private:
	int hash(int key, int size = 10){
		return key%size;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	HashTable h;
	while (true){
		int number;
		std::cin >> number;
		h.chaining(number);
		h.print();
	}

	return 0;
}

