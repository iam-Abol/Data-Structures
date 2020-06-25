#include "stdafx.h"
#include <iostream>

class Node{
public:
	int element;
	Node *next;

	Node(int data){
		this->element = data;
	}

	Node(){

	}


};
class LinkedList{
	Node *head = new Node;

	int size = 0;
public:
	void insertLast(Node *newNode){

		Node *t;
		if (size == 0){
			head = newNode;
			size++;
		}
		else{
			t = head;
			while (t->next){
				t = t->next;

			}
			t->next = newNode;
			size++;
		}

	}
	void print(){
		Node *temp;
		temp = head;
		int i = 0;
		std::cout << "Number : \n";
		while (temp){

			std::cout << temp->element;
			if (i < size - 1)
				std::cout << "---->";
			temp = temp->next;
			i++;
		}
		std::cout << std::endl;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	std::cout << "enter number of numbers : ";
	std::cin >> n;
	int input;
	LinkedList obj;
	int i = 0;
	while (i < n)
	{
		std::cout << "enter a number : ";
		std::cin >> input;

		Node *node = new Node(input);

		obj.insertLast(node);
		i++;
	}
	obj.print();
	system("pause");
	return 0;
}

