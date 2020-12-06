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
	int find(int number){
		if (size == 0){
			return false;
		}
		else
		{
			Node* temp = this;
			while (temp)
			{
				if (temp->element == number)
					return true;
				temp = temp->next;
			}
			return false;
		}
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
	
};
class HashTable{
	Node *array;
public:
	HashTable(){
		array = new Node[10];
	}
	void chaining(int newNumber){
		int index = hash(newNumber, 10);
		if (array[index].element == -1){
			array[index].element = newNumber;
		}
		else{
			Node* newNode = new Node(newNumber);
			Node* temp = &(array[index]);
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = newNode;
			
		}
		array[index].size++;
	}
	void search(int number){
		int index = hash(number);
		bool result=array[index].find(number);
		if (result)
			std::cout << "the number is at tree" << std::endl;
		else
			std::cout << "the number isnot at tree" << std::endl;
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
	int i = 0;
	while (i<5){
		int n;
		std::cin >> n;
		h.chaining(n);
		h.print();
		i++;
	}
	int number;
	std::cin >> number;

	h.search(number);
	return 0;
}

