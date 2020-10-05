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
	int getElement();
	Node setLeftChild(Node *newNode);

	
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

int Node::getElement(){
	return element;
}
Node Node::setLeftChild(Node *newNode){
	leftChild->element = newNode->element;
	leftChild->leftChild = newNode->leftChild;
	leftChild->rightChild = newNode->rightChild;
};
