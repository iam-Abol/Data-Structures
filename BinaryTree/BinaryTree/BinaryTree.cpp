#include "stdafx.h"
#include <iostream>
#include <queue>
#include <list>
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
	int depth;
private:

public:
	BinaryTree(){
		size = 0;
		root = new Node;
		depth = 1;

	}
	Node *getRoot(){
		return root;
	}
	void setDepth(){
		int equalSize = 1;
		for (int i = 1; i < depth; i++){
			equalSize *= 2;

		}
		if (size == equalSize){
			depth++;
		}
	}
	void recursiveAdd(Node *root, Node *newNode, int i = 1){
		if (i < depth){
			if (root->leftChild == NULL){
				root->leftChild = newNode;

				size++;
				return;
			}
			else if (root->rightChild == NULL){
				root->rightChild = newNode;
				size++;
				return;
			}
			else{
				recursiveAdd(root->leftChild, newNode, i++);
				recursiveAdd(root->rightChild, newNode, i++);
			}
		}
		else{
			return;
		}

	}

	void add(Node *newNode){
		if (root->element == NULL){
			root = newNode;
			size++;
		}
		else{
			recursiveAdd(root, newNode);
		}


		std::cout << "Added" << std::endl;
	}
	void print(){

		if (root->element == NULL){
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
		obj.setDepth();
		obj.print();
	}




	system("pause");
	return 0;
}

