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
	int isLeaf();
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
	Node* getFather(int number, Node* node);
	BinarySearchTree();
	~BinarySearchTree();
	void print();


	Node* getHead();
};

//////////// main ////////////
//TO DO
/*
finish print
finish remove
*/
int _tmain(int argc, _TCHAR* argv[])
{
	BinarySearchTree tree;
	int choice;
	while (1){
		std::cout << "ENTER A NUMBER : " << std::endl;;
		std::cout << "1-add\n2-search\n3-remove\n4-size\n5-print\n6-exit\n";
		std::cin >> choice;
		if (choice == 1){
			std::cout << "ENTER A NUMBER FOR ADD : ";
			int number;
			std::cin >> number;
			Node* newNode = new Node(number);
			tree.add(newNode);
		}
		else if (choice == 2){
			std::cout << "ENTER A NUMBER FOR SEARCH : ";
			int number;
			std::cin >> number;
			Node* p = tree.search(number);
			if (p == NULL)
				std::cout << "- - -> YOUR NUMBER ISNOT AT TREE ! <- - -" << std::endl;
			else
				std::cout << "- - -> YOUR NUMBER FOUND ! <- - -" << std::endl;
		}
		else if (choice == 3){
			int number;
			std::cout << "ENTER A NUMBER FOR REMOVE : ";
			std::cin >> number;
			tree.remove(number);
		}
		else if (choice == 4){
			int size = tree.getSize();
			std::cout << "SIZE OF TREE :- - -> " << size << std::endl;
		}
		else if (choice == 5){
			tree.print();
		}
		else if (choice == 6){
			break;
		}

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
int Node::isLeaf(){
	if (leftChild == NULL && rightChild == NULL)
		return true;
	else
		return false;
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
	/*Node* addressOfNumber = search(number);
	if (addressOfNumber != NULL){
	Node* temp = addressOfNumber;
	if (temp->getLeftChild() == NULL&&temp->getRightChild() == NULL)
	temp = NULL;
	else if (temp->getLeftChild() == NULL&&temp->getRightChild() != NULL)
	{
	temp = temp->getRightChild();
	}
	else if (temp->getLeftChild() != NULL&&temp->getRightChild() == NULL)
	{
	temp = temp->getLeftChild();
	}
	else{

	}
	}
	else{
	std::cout << "- - -> " << number << " is not in a tree <- - - " << std::endl;
	}*/
	if (number == head->getElement()){

	}
	else
	{
		Node* father = getFather(number, head);
		std::cout << father->getElement() << std::endl;
	}
}
Node* BinarySearchTree::getFather(int number, Node* node){
	if (node->getRightChild()->getElement() == number){
		return node;
	}
	else if (node->getLeftChild()->getElement() == number){
		return node;
	}
	else
	{
		return NULL;
	}
	else{
		if (number >= node->getElement()){
			getFather(number, node->getLeftChild());
		}
		else{
			getFather(number, node->getRightChild());
		}
	}


}
void BinarySearchTree::print(){
	if (size == 0){
		std::cout << "- - -> TREE IS EMPTY ! <- - - " << std::endl;
	}
	else
	{
		std::queue <Node*> q;
		q.push(head);
		std::cout << "NUMBERS THAT IN THE TREE ARE : " << std::endl;
		while (q.empty() == false){
			Node* temp = q.front();
			std::cout << temp->getElement() << std::endl;
			q.pop();
			if (temp->getLeftChild() != NULL)
				q.push(temp->getLeftChild());
			if (temp->getRightChild() != NULL)
				q.push(temp->getRightChild());
		}
	}


}
Node* BinarySearchTree::getHead(){
	return head;
}