#include "stdafx.h"
#include <iostream>
//////////// Node class skeleton ////////////
class Node{

private:

	int element;
	Node *leftChild, *rightChild;

public:
	Node();
	Node(int element);
	
};

//////////// main ////////////

int _tmain(int argc, _TCHAR* argv[])
{
	Node n;
	return 0;
}

//////////// Node class functions ////////////

Node::Node(){
	element = 0;
	leftChild = NULL;
	rightChild = NULL;
}

Node::Node(int element){
	this->element = element;
	leftChild = NULL;
	rightChild = NULL;
}