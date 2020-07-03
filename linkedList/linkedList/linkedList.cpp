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
protected:
	void addRecursive(Node *temp, Node *node){
		if (!temp->next){
			temp->next = node;
		}
		else{
			return addRecursive(temp->next, node);
		}
		size++;
	}
	void recursiveRemove(Node *temp){
		if (!temp->next->next){
			temp->next = NULL;
		}
		else{
			return recursiveRemove(temp->next);
		}
		size--;
	}
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
	void insertAfter(int after, Node *node){
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
	void reverse(){
		Node *current = head;
		Node* next = NULL;
		Node *preview = NULL;
		if (size == 1){
			std::cout << "list has 1 element" << std::endl;
		}
		else{
			while (current){
				next = current->next;
				current->next = preview;
				preview = current;
				current = next;
			}
			head = preview;
			print();
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
				std::cout << "<--->";
			temp = temp->next;
			i++;
		}
		std::cout << std::endl;

	}
	void insertFirst(Node *first){
		insertAfter(1, first);
		int temp = head->element;
		head->element = head->next->element;
		head->next->element = temp;
	}

	void add(Node *node){
		Node *temp = head;
		addRecursive(temp, node);
	}
	void removeWithRecursive(){
		if (size == 0){
			std::cout << "list is empty!" << std::endl;
		}
		else if (size == 1){
			head = NULL;
		}
		else{
			Node *temp = head;
			recursiveRemove(temp);

		}

	}
	~LinkedList(){
		delete head;

	}
};
int main()
{
	system("color 4");
	int choice;
	LinkedList obj;

	while (1){

		std::cout << "1_insert last \n2_remove \n3_insert after\n4_print\n5_insert first\n6_reverse\n7_add\n8_recursive remove\n";
		std::cin >> choice;
		if (choice == 1){
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
		if (choice == 2){
			obj.remove();
		}
		if (choice == 3){
			int after;
			std::cout << "after which number do you want to insert ? : ";
			std::cin >> after;
			std::cout << "enter a number :";
			int number;
			std::cin >> number;

			Node *node = new Node(number);
			obj.insertAfter(after, node);
		}
		if (choice == 4){
			obj.print();
		}
		if (choice == 5){
			std::cout << "enter a number :";
			int number;
			std::cin >> number;
			Node *first = new Node(number);
			obj.insertFirst(first);
		}
		if (choice == 6){
			obj.reverse();
		}
		if (choice == 7){
			int number;
			std::cout << "Enter a number : ";
			std::cin >> number;
			Node *node = new Node(number);
			obj.add(node);
		}
		if (choice == 8){
			obj.removeWithRecursive();
		}
	}
	system("pause");
	return 0;
}
