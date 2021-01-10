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
public:
	AVLTree(){
		root = new Node(NULL);
	}
	void insert(Node *newNode){
		if (root==NULL)
		{
			root = newNode;
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
			if (newNode->getElement() > temp->getElement){
				if (temp->getRightChild()==NULL)
				{
					temp->setRightChild(newNode);
					return;
				}
				else{
					recursiveInsert(temp->getRightChild(), newNode);
				}
			}
			
		}

	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

