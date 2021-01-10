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
	Node(){
		*this = NULL;
	}
	int getElement(){
		return element;
	}
	void setElement(int element){
		this->element = element;
	}
	Node* getLeftChild(){
		return leftChild;
	}
	void setLeftChild(Node *newNode)
	{
		leftChild = newNode;
	}
	Node* getRightChild(){
		return rightChild;
	}
	void setRightChild(Node *newNode){
		rightChild = newNode;
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
	int size;
public:
	AVLTree(){
		root = new Node(NULL);
		size = 0;
	}
	void insert(Node *newNode){
		if (size==0)
		{
			root = newNode;
			size++;
		}
		else{
			recursiveInsert(root, newNode);
		}
		
	}
	
	~AVLTree(){
		delete root;
	}
private:
	void recursiveInsert(Node *temp,Node *newNode){
		if (temp==NULL)
		{
			return;
		}
		else
		{
			if (newNode->getElement() > temp->getElement()){
				if (temp->getRightChild()==NULL)
				{
					temp->setRightChild(newNode);
					size++;
					return;
				}
				else{
					recursiveInsert(temp->getRightChild(), newNode);
				}
			}
			else if (newNode->getElement() < temp->getElement()){
				if (temp->getLeftChild() == NULL)
				{
					temp->setLeftChild(newNode);
					size++;
					return;
				}
				else{
					recursiveInsert(temp->getLeftChild(), newNode);
				}
			}
			
		}

	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	int number;
	AVLTree t;
	while (std::cin>>number)
	{
		Node* n = new Node(number);
		t.insert(n);
	}
	return 0;
}

