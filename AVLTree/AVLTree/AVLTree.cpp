#include "stdafx.h"
#include <iostream>
#include <string>
#include <queue>
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
			else if (rightChild == NULL){
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
				if (std::abs(leftChild->getHeight() + 1) < 2)
					return true;
				else
					return false;
			}
			else if (leftChild == NULL){
				if (std::abs(rightChild->getHeight() + 1) < 2)
					return true;
				else
					return false;
			}
			else{
				if (std::abs((leftChild->getHeight() + 1) - (rightChild->getHeight() + 1)) < 2)
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


///////////////////////////////////////////////////


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
	Node* search(Node *temp, int key){
		if (temp == NULL)
		{
			return NULL;
		}
		else{
			if (temp->getElement() == key)
				return temp;
			else if (key < temp->getElement())
				search(temp->getLeftChild(), key);
			else if (key>temp->getElement()){
				search(temp->getRightChild(), key);
			}
		}
	}
	Node* getRoot() const{
		return root;
	}
	void print(){
		if (size == 0)
		{
			std::cout << "- - -> TREE IS EMPTY <- - -" << std::endl;
		}
		else{
			std::cout << "ELEMENTS IN TREE : " << std::endl;
			std::queue<Node*> q;
			q.push(root);
			while (!q.empty())
			{
				Node *t = q.front();
				q.pop();
				std::cout << t->getElement() << std::endl;
				if (t->getLeftChild() != NULL)
					q.push(t->getLeftChild());
				if (t->getRightChild() != NULL)
					q.push(t->getRightChild());
			}
		}
	}
	~AVLTree(){
		delete root;
	}
private:
	std::string getTypeOfRotation(Node *imbalancedNode){
		std::pair<std::string, int> type[4];
		type[0] = std::make_pair("LL", 0);
		if (imbalancedNode->getLeftChild() != NULL&&imbalancedNode->getLeftChild()->getLeftChild() != NULL)
			type[0].second = imbalancedNode->getLeftChild()->getLeftChild()->getHeight() + 1;
		type[1] = std::make_pair("LR", 0);
		if (imbalancedNode->getLeftChild() != NULL&&imbalancedNode->getLeftChild()->getRightChild() != NULL)
			type[1].second = imbalancedNode->getLeftChild()->getRightChild()->getHeight() + 1;
		type[2] = std::make_pair("RR", 0);
		if (imbalancedNode->getRightChild() != NULL&&imbalancedNode->getRightChild()->getRightChild() != NULL)
			type[2].second = imbalancedNode->getRightChild()->getRightChild()->getHeight() + 1;
		type[3] = std::make_pair("RL", 0);
		if (imbalancedNode->getRightChild() != NULL&&imbalancedNode->getRightChild()->getLeftChild() != NULL)
			type[3].second = imbalancedNode->getRightChild()->getLeftChild()->getHeight() + 1;
		std::pair<std::string, int> max = type[0];
		for (int i = 0; i < 4; i++)
		{
			if (type[i].second>max.second)
				max = type[i];
		}
		return max.first;
	}
	void rotate(Node *imbalancedNode){
		std::string typeOfRotation = getTypeOfRotation(imbalancedNode);
		if (typeOfRotation == "LL")
		{
			if (imbalancedNode->getElement() == root->getElement()){
				Node *r = root;
				root = imbalancedNode->getLeftChild();
				root->setParent(NULL);
				r->setLeftChild(root->getRightChild());
				if (r->getLeftChild() != NULL)
					r->getLeftChild()->setParent(r);
				root->setRightChild(r);
				r->setParent(root);
			}
			else{
				/*imbalancedNode->getLeftChild()->setParent(imbalancedNode->getParent());
				imbalancedNode->getParent()->setLeftChild(imbalancedNode->getLeftChild());
				imbalancedNode->setParent(imbalancedNode->getLeftChild());
				Node *p = imbalancedNode->getParent();

				imbalancedNode->setLeftChild(imbalancedNode->getLeftChild()->getRightChild());
				p->setRightChild(imbalancedNode);*/
				Node *parent = imbalancedNode->getParent();
				if (parent->getLeftChild()==imbalancedNode)
				{
					parent->setLeftChild(imbalancedNode->getLeftChild());
					parent->getLeftChild()->setParent(parent);
					imbalancedNode->setLeftChild(imbalancedNode->getLeftChild()->getRightChild());
					imbalancedNode->getLeftChild()->setParent(imbalancedNode);
					imbalancedNode->setParent(parent->getLeftChild());
					parent->getLeftChild()->setRightChild(imbalancedNode);
				}
				else{
					parent->setRightChild(imbalancedNode->getLeftChild());
					parent->getRightChild()->setParent(parent);
					imbalancedNode->setLeftChild(imbalancedNode->getLeftChild()->getRightChild());
					imbalancedNode->getLeftChild()->setParent(imbalancedNode);
					imbalancedNode->setParent(parent->getRightChild());
					parent->getRightChild()->setRightChild(imbalancedNode);
				}
			}
		}
		else if (typeOfRotation == "LR"){
			if (imbalancedNode->getElement() == root->getElement()){
				Node *r = root;
				root = imbalancedNode->getLeftChild()->getRightChild();
				root->setParent(NULL);
				r->getLeftChild()->setRightChild(NULL);
				r->getLeftChild()->setRightChild(root->getLeftChild());
				if (root->getLeftChild() != NULL)
					root->getLeftChild()->setParent(r->getLeftChild());
				root->setLeftChild(NULL);
				root->setLeftChild(r->getLeftChild());
				r->getLeftChild()->setParent(root);
				r->setLeftChild(NULL);
				r->setLeftChild(root->getRightChild());
				if (root->getRightChild() != NULL)
					root->getRightChild()->setParent(r);
				root->setRightChild(r);
				r->setParent(root);
			}
			else{
				/*
				Node *p = imbalancedNode->getParent();
				p->setLeftChild(imbalancedNode->getLeftChild()->getRightChild());
				p->getLeftChild()->setParent(p);
				imbalancedNode->getLeftChild()->setRightChild(p->getLeftChild()->getLeftChild());
				if (imbalancedNode->getLeftChild()->getRightChild() != NULL)
					imbalancedNode->getLeftChild()->getRightChild()->setParent(imbalancedNode->getLeftChild());
				p->getLeftChild()->setLeftChild(imbalancedNode->getLeftChild());
				imbalancedNode->getLeftChild()->setParent(p->getLeftChild());
				imbalancedNode->setLeftChild(p->getLeftChild()->getRightChild());
				if (imbalancedNode->getLeftChild() != NULL)
					imbalancedNode->getLeftChild()->setParent(imbalancedNode);
				imbalancedNode->setParent(p->getLeftChild());
				p->getLeftChild()->setRightChild(imbalancedNode);*/

			}
		}
		else if (typeOfRotation == "RR"){
			if (imbalancedNode->getElement() == root->getElement())
			{
				Node *r = root;
				root = root->getRightChild();
				root->setParent(NULL);
				r->setRightChild(root->getLeftChild());
				if (root->getLeftChild() != NULL)
					root->getLeftChild()->setParent(r);
				r->setParent(root);
				root->setLeftChild(r);
			}
			else{
				Node *parent = imbalancedNode->getParent();
				


			}
		}
		else if (typeOfRotation == "RL"){
			if (imbalancedNode->getElement() == root->getElement()){

			}
			else{

			}
		}
		/*LL    LR    RR    RL*/
	}
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
					if (temp->isBalanced() == false){
						std::cout << "tree is imbalanced " << std::endl;
						rotate(temp);
					}
					return;
				}
				else{
					recursiveInsert(temp->getRightChild(), newNode);
					if (temp->isBalanced() == false){
						std::cout << "tree is imbalanced " << std::endl;
						rotate(temp);
					}

				}
			}
			else if (newNode->getElement() < temp->getElement()){
				if (temp->getLeftChild() == NULL)
				{
					temp->setLeftChild(newNode);
					size++;
					newNode->setParent(temp);
					if (temp->isBalanced() == false){
						std::cout << "tree is imbalanced " << std::endl;
						rotate(temp);
					}

					return;
				}
				else{
					recursiveInsert(temp->getLeftChild(), newNode);
					if (temp->isBalanced() == false){
						std::cout << "tree is imbalanced " << std::endl;
						rotate(temp);
					}

				}
			}

		}

	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	int choice;
	AVLTree tree;
	while (true)
	{
		std::cout << "1-insert\n2-search\n3-print" << std::endl;
		std::cin >> choice;
		if (choice == 1)
		{
			std::cout << "Enter a number : ";
			int number;
			std::cin >> number;
			Node *newNode = new Node(number);
			tree.insert(newNode);
		}
		else if (choice == 2){
			int number;
			std::cout << "Enter a number for search : ";
			std::cin >> number;
			if (tree.search(tree.getRoot(), number) == NULL)
				std::cout << "NOT FOUND" << std::endl;
			else
				std::cout << "FOUND" << std::endl;
		}
		else if (choice == 3)
		{
			tree.print();
		}
	}
	return 0;
}

