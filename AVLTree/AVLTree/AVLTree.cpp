#include "stdafx.h"
#include <iostream>
int max(int a, int b){
	return a > b ? a : b;
}
class Node{
	int element;
	Node *leftChild, *rightChild;
	Node *parent;
	int height;
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
	int getHeight(){
		if (isLeaf()){
			return 0;
		}
		else{
			if (leftChild == NULL)
			{
				height = rightChild->getHeight() + 1;
			}
			else if(rightChild==NULL){
				height = leftChild->getHeight() + 1;
			}
			else{
				height = max(rightChild->getHeight(), leftChild->getHeight()) + 1;
			}
			return height;
		}


	}
	bool isBalanced(){
		if (isLeaf())
			return true;
		else{
			if (rightChild == NULL){
				if (std::abs(leftChild->getHeight()+1) < 2)
					return true;
				else
					return false;
			}
			else if (leftChild == NULL){
				if (std::abs(rightChild->getHeight()+1) < 2)
					return true;
				else
					return false;
			}
			else{
				if (std::abs((leftChild->getHeight()+1) - (rightChild->getHeight()+1)) < 2)
					return true;
				else{
					return false;
				}
			}
		}
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
		return leftChild == NULL&&rightChild == NULL ? true : false;
	}
	Node* getParent(){
		return parent;
	}
	void setParent(Node *newNode){
		parent = newNode;
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
		if (size == 0)
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
	void recursiveInsert(Node *temp, Node *newNode){
		if (temp == NULL)
		{
			return;
		}
		else
		{
			if (newNode->getElement() > temp->getElement()){
				if (temp->getRightChild() == NULL)
				{
					temp->setRightChild(newNode);
					size++;
					newNode->setParent(temp);
					if (temp->isBalanced() == false)
						std::cout << "tree is imbalanced" << std::endl;
					return;
				}
				else{
					recursiveInsert(temp->getRightChild(), newNode);
					if (temp->isBalanced() == false)
						std::cout << "tree is imbalanced "<<temp->getElement() << std::endl;
				}
			}
			else if (newNode->getElement() < temp->getElement()){
				if (temp->getLeftChild() == NULL)
				{
					temp->setLeftChild(newNode);
					size++;
					newNode->setParent(temp);
					if (temp->isBalanced() == false)
						std::cout << "tree is imbalanced" << std::endl;
					return;
				}
				else{
					recursiveInsert(temp->getLeftChild(), newNode);
					if (temp->isBalanced() == false)
						std::cout << "tree is imbalanced" << std::endl;
				}
			}

		}

	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	int number;
	AVLTree a;
	while (std::cin>>number)
	{
		Node *n = new Node(number);
		a.insert(n);
	}
	return 0;
}

