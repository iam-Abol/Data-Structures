#include "stdafx.h"
#include <iostream>
class Node{
public:
	int element;
	Node * next;
	Node(){}
	Node(int element){
		this->element = element;
	}
};
class Queue{
	Node *head = new Node;
	int size = 0;

public:
	bool isEmpty(){
		if (size == 0)
			return true;
		else
			return false;
	}
	int getSize(){
		return size;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

