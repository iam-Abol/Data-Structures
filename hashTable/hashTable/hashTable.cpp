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
};
class HashTable{
	Node array[10];
public:
	HashTable(){

	}
	void chaining(int newNumber){
		int index = hash(newNumber, 10);
		if (array[index] == NULL){

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

