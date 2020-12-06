#include "stdafx.h"
#include <iostream>
class Node{
public:
	int element;
	Node *next;
	Node(){
		element = NULL;
		next = NULL;
	}
	Node(int number){
		element = number;
	}

	void print()
	{
		Node* temp = this;
		while (temp->element){
			std::cout << temp->element << "\t";
		}
		std::cout << std::endl;
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
			if (temp->element > temp->next->element){
				int s = temp->element;
				temp->element = temp->next->element;
				temp->next->element = s;
			}
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
	}

	return 0;
}

