#include "stdafx.h"
#include <iostream>
#include <queue>

class Node{
public:
	int element;
	Node *leftChild;
	Node *rightChild;
	Node(){
		element = NULL;
		leftChild = NULL;
		rightChild = NULL;

	}

	Node(int element) :element(element), leftChild(NULL), rightChild(NULL){}
	//~Node(){
	//	delete leftChild;
	//	delete rightChild;
	//}
};

class BinaryTree{


	Node *root;
	int size;

private:
	//void recursiveAdd(Node*root, Node *newNode){
	//	
	//	if (root== NULL){
	//		root = newNode;
	//		return;
	//	}
	//	
	//}

public:
	BinaryTree(){
		size = 0;
		root = new Node;
		root->element = 10;
		Node *left = new Node(20);
		Node *right = new Node(30);
		root->leftChild = left;
		root->rightChild = right;
	}
	Node getRoot(){
		return *root;
	}

	//void add(Node*newNode){
	//	if (root->element == NULL){
	//		root = newNode;
	//		size++;
	//	
	//	}
	//	else{
	//		recursiveAdd(root, newNode);
	//	}
	//	
	//}
	void print(){
		std::queue <Node> q;

		q.push(*root);
		for (; q.size() != 0;){
			Node temp = q.front();
			q.pop();

			std::cout << temp.element << std::endl;
			if (temp.leftChild != NULL)
				q.push(*temp.leftChild);
			if (temp.rightChild != NULL)
				q.push(*temp.rightChild);
		}
	}
	~BinaryTree(){
		delete root;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{

	BinaryTree obj;


	obj.print();


	system("pause");
	return 0;
}

