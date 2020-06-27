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
	~Node(){
		delete next;
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
	void insertAfter(int after,Node *node){
		if (after > size){
			std::cout << "list size is short" << std::endl;
		}
		else if (after == size){
			insertLast(node);
			size++;
		}
		else{
			Node *temp;
			temp = head;
			int i = 1;
			while (i < after){
				
				temp = temp->next;
				i++;
			}
			node->next = temp->next;
			temp->next = node;

			size++;
		}
	}
	void remove(){
		Node *temp;

		if (size == 0){
			std::cout << "-->the List is empty!<--";
		}
		else if (size == 1){
			head = NULL;
			size--;
		}
		else{
			temp = head;
			while (temp->next->next){
				temp = temp->next;
			}
			temp->next = NULL;
			size--;
		}
		print();
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
	~LinkedList(){
		delete head;

	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	system("color 4");
	int choose;
	LinkedList obj;

	while (1){

		std::cout << "1_insert last \n2_remove \n3_insert after\n4_print\n";
		std::cin >> choose;
		if (choose == 1){
			int size;
			std::cout << "enter number of numbers : ";
			std::cin >> size;
			int input;

			int i = 0;
			while (i < size)
			{
				std::cout << "enter a number : ";
				std::cin >> input;

				Node *node = new Node(input);

				obj.insertLast(node);
				i++;

			}
			obj.print();

		}
		if (choose == 2){
			obj.remove();
		}
		if (choose == 3){
			int after;
			std::cout << "after which number do you want to insert ? : ";
			std::cin >> after;
			std::cout << "enter a number :";
			int number;
			std::cin >> number;
			
			Node *node = new Node(number);
			obj.insertAfter(after,node);
		}
		if (choose == 4){
			obj.print();
		}

	}
	system("pause");
	return 0;
}
