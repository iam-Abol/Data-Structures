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
		
	}
	Node getRoot(){
		return *root;
	}

	void add(Node *newNode){
		if (size == 0){
			size++;
			root = newNode;
		}
		else{
			std::queue <Node> q;
			q.push(*root);
	
			while (true){
				Node *temp = new Node;
				temp = &q.front();
				q.pop();
				if (temp->leftChild == NULL){
					temp->leftChild = newNode;
					size++;
					break;
				}
				else if (temp->rightChild == NULL){
					temp->rightChild = newNode;
					size++;
					break;
				}
				q.push(*temp->leftChild);
				q.push(*temp->rightChild);
					
			}
		}
		std::cout << "-->!Added!<--" << std::endl;

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
public:
	void print(){
		
		if (root->element==NULL){
			std::cout << "!-->EMPTY<--!" << std::endl;
		}
		else {
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
	}
	~BinaryTree(){
		delete root;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{

	BinaryTree obj;
	while (1){
		int number;
		std::cin >> number;
		Node *node = new Node(number);
		obj.add(node);
		obj.print();
	}

	


	system("pause");
	return 0;
}

