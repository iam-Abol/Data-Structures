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
		if (temp==NULL)
		{
			return NULL;
		}
		else{
			if (temp->getElement() == key)
				return temp;
			else if (key < temp->getElement())
				search(temp->getLeftChild(),key);
			else if(key>temp->getElement()){
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
				imbalancedNode->getLeftChild()->setParent(imbalancedNode->getParent());
				imbalancedNode->getParent()->setLeftChild(imbalancedNode->getLeftChild());
				imbalancedNode->setParent(imbalancedNode->getLeftChild());
				Node *p = imbalancedNode->getParent();

				imbalancedNode->setLeftChild(imbalancedNode->getLeftChild()->getRightChild());
				p->setRightChild(imbalancedNode);
			}
		}
		else if (typeOfRotation == "LR"){
			if (imbalancedNode->getElement() == root->getElement()){
				Node *r = root;
				root = imbalancedNode->getLeftChild()->getRightChild();
				root->setParent(NULL);

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
	int number;
	AVLTree a;
	while (std::cin >> number)
	{
		Node *n = new Node(number);
		a.insert(n);
		a.print();
	}
	return 0;
}

