#include "stdafx.h"
#include <iostream>
#include <queue>

//////////// Node class skeleton ////////////

class Node{

private:

	int element;
	Node *leftChild, *rightChild;

public:

	Node();
	Node(int element);
	int getElement();
	void setLeftChild(Node *newNode);
	void setRightChild(Node *newNode);
	~Node();
	Node *getLeftChild();
	Node *getRightChild();

};

//////////// BinarySearchTree class skeleton ////////////

class BinarySearchTree{

private:
	Node *head;
	int size;

public:
	void add(Node* newNode);
	void search(int number);
	void remove(int number);
	int getSize();
	BinarySearchTree();
	~BinarySearchTree();
	void print();
};

//////////// main ////////////

int _tmain(int argc, _TCHAR* argv[])
{
	BinarySearchTree tree;
	for (int i = 5; i >= 0; i--){
		int number;
		std::cin >> number;
		Node* newNode = new Node(number);
		tree.add(newNode);
		
		std::cin >> number;
		tree.search(number);
	}
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
void Node::setLeftChild(Node *newNode){
	leftChild = newNode;
};
void Node::setRightChild(Node *newNode){
	rightChild = newNode;
};
Node* Node::getLeftChild(){
	return leftChild;
}
Node* Node::getRightChild(){
	return rightChild;
}
Node::~Node(){
	delete leftChild;
	delete rightChild;
}

//////////// BinarySearchTree class functions ////////////

BinarySearchTree::BinarySearchTree(){
	head = new Node;
	size = 0;
}
BinarySearchTree::~BinarySearchTree(){
	delete head;
}

void BinarySearchTree::add(Node* newNode){
	if (size == 0){
		size++;
		head = newNode;
	}
	else{
		bool isAdded = false;
		Node *temp = head;
		while (isAdded == false){
			if (newNode->getElement() >= temp->getElement()){
				if (temp->getLeftChild() == NULL){
					temp->setLeftChild(newNode);
					isAdded = true;
					size++;
				}
				else
					temp = temp->getLeftChild();

			}
			else{

				if (temp->getRightChild() == NULL){
					temp->setRightChild(newNode);
					isAdded = true;
					size++;
				}
				else
					temp = temp->getRightChild();

			}
		}
	}
}
int BinarySearchTree::getSize(){
	return size;
}
void BinarySearchTree::search(int number){
	if (size == 0)
		std::cout << "- - -> ! TREE IS EMPTY ! <- - -" << std::endl;
	else{
		if (number == head->getElement())
			std::cout << number << "- - -> ! is in head ! <- - -" << std::endl;
		else{
			Node* temp = head;
			bool shouldBreak = false;
			while (!shouldBreak){
				if (number >= temp->getElement()){
					if (temp->getLeftChild() != NULL)
						temp = temp->getLeftChild();
					else
					{
						if (temp->getElement() == number){
							std::cout << "- - -> ! number found ! <- - -" << std::endl;
						}
						else
							std::cout << "- - -> ! number didn't find ! <- - -" << std::endl;
						shouldBreak = true;
					}
				}
				else{
					if (temp->getRightChild() != NULL)
						temp = temp->getRightChild();
					else{
						if (number == temp->getElement())
							std::cout << "- - -> ! number found ! <- - -" << std::endl;
						else
							std::cout << "- - -> ! number didn't find ! <- - -" << std::endl;
						shouldBreak = true;
					}
				}
			}
		}
	}
}