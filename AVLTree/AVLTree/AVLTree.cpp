#include "stdafx.h"
#include <iostream>
class Node{
	int element;
	Node *leftChild, *rightChild;
public:
	Node(int element){
		this->element = element;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Node n(10);
	return 0;
}

