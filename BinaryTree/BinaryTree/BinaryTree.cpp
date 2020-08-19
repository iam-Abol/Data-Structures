#include "stdafx.h"
#include <iostream>
class Node{
public:
	int element;
	Node *leftChild;
	Node *rightChild;
	Node(){
		element = NULL;
		leftChild = NULL;
		rightChild = NULL;
	}
	Node(int element) :element(element),leftChild(NULL),rightChild(NULL){}
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
	system("pause");
	return 0;
}

