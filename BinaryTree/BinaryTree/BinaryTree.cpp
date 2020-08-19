#include "stdafx.h"
#include <iostream>
class Node{
public:
	int element;
	Node *leftChild;
	Node *rightChild;
	
	~Node(){
		delete leftChild;
		delete rightChild;
	}
};
class BinaryTree{
	Node *root = new Node;
public :
	
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

