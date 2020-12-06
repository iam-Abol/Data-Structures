#include "stdafx.h"
#include <iostream>
class Node{
public:
	int element;
	Node *next;
	Node(){
		element = 0;
		next = NULL;
	}
	Node(int number){
		element = number;
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
		if (array[index].element==NULL){
			array[index].element = newNumber;
		}
		else{
			Node* newNode=new Node(newNumber);
			Node* temp = &(array[index]);
			while (temp->next != NULL)
				temp = temp->next;
			temp->next=
		}
	}
};
int hash(int key, int size = 10){
	return key%size;
}
int _tmain(int argc, _TCHAR* argv[])
{

	return 0;
}

