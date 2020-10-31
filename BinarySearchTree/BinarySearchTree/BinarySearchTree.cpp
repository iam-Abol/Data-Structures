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
	Node* search(int number);
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
	int choice;
	while (1){
		std::cout << "ENTER A NUMBER : ";
		std::cout << "1-add\n2-search\n3-remove\n4-size\n5-print\n";
		std::cin >> choice;
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
Node* BinarySearchTree::search(int number){
	if (size == 0){
		//std::cout << "- - -> ! TREE IS EMPTY ! <- - -" << std::endl;
		return NULL;
	}

	else{
		if (number == head->getElement()){
			//std::cout << number << "- - -> ! is in head ! <- - -" << std::endl;
			return head;
		}

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
							//std::cout << "- - -> ! number found ! <- - -" << std::endl;
							return temp;
						}
						else{
							//std::cout << "- - -> ! number didn't find ! <- - -" << std::endl;
							return NULL;
						}

						shouldBreak = true;
					}
				}
				else{
					if (temp->getRightChild() != NULL)
						temp = temp->getRightChild();
					else{
						if (number == temp->getElement()){
							//std::cout << "- - -> ! number found ! <- - -" << std::endl;
							return temp;
						}

						else{
							//std::cout << "- - -> ! number didn't find ! <- - -" << std::endl;
							return NULL;
						}

						shouldBreak = true;
					}
				}
			}
		}
	}
}
void BinarySearchTree::remove(int number){
	Node* addressOfNumber = search(number);
	if (addressOfNumber!=NULL){
		
	}
	else{
		std::cout << "- - -> " << number << " is not in a tree <- - - " << std::endl;
	}

}
