#include "stdafx.h"
#include <iostream>
class Node{
	int element;
	Node *leftChild, *rightChild;
	int height, balanceFactor;
public:
	Node(int element){
		this->element = element;
	}
	bool isLeaf(){
		return leftChild == NULL&&rightChild == NULL ? true: false;
	}
	~Node(){
		delete leftChild;
		delete rightChild;
	}
};
class AVLTree{
private:
	Node *root;
public:
	AVLTree(){
		root = new Node(0);
	}


	~AVLTree(){
		delete root;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Node n(10);
	return 0;
}

