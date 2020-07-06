#include "stdafx.h"
#include <iostream>
#include <string>
template <class T>
class Node{
public:
	T element;
	Node *next;

	Node(T data){
		this->element = data;
	}

	Node(){

	}
	~Node(){
		delete next;
	}

};
template <class T>
class LinkedList{
	Node<T> *head = new Node<T>;

	int size = 0;
protected:
	void addRecursive(Node<T> *temp, Node<T> *node){
		if (!temp->next){
			temp->next = node;
		}
		else{
			return addRecursive(temp->next, node);
		}
		size++;
	}
	void recursiveRemove(Node<T> *temp){
		if (!temp->next->next){
			temp->next = NULL;
		}
		else{
			return recursiveRemove(temp->next);
		}
		size--;
	}
public:
	void insertLast(Node<T> *newNode){

		Node<T> *t;
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
	void insertAfter(int after, Node<T> *node){
		if (after > size){
			std::cout << "list size is short" << std::endl;
		}
		else if (after == size){
			insertLast(node);
			size++;
		}
		else{
			Node<T> *temp;
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
		Node<T> *current = head;
		Node<T>* next = NULL;
		Node<T> *preview = NULL;
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
		Node<T> *temp;

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
		if (size == 0){
			std::cout << "-->!list is empty!<--" << std::endl;
		}
		else{
			Node<T> *temp;
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
	}
	void insertFirst(Node<T> *first){
		insertAfter(1, first);
		T temp = head->element;
		head->element = head->next->element;
		head->next->element = temp;
	}

	void add(Node<T> *node){
		Node<T> *temp = head;
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
			Node<T> *temp = head;
			recursiveRemove(temp);

		}

	}
	~LinkedList(){
		delete head;

	}
};
void inputChar(){
	int choice;
	LinkedList<char> obj;
	char input;
	char c;
	while (1){

		std::cout << "1_insert last \n2_remove \n3_insert after\n4_print\n5_insert first\n6_reverse\n7_add\n8_recursive remove\n";
		std::cin >> choice;
		if (choice == 1){
			int size;
			std::cout << "enter number of char : ";
			std::cin >> size;


			int i = 0;
			while (i < size)
			{
				std::cout << "enter a char : ";
				std::cin >> input;

				Node<char> *node = new Node<char>(input);

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
			std::cout << "enter a char :";

			std::cin >> c;

			Node<char> *node = new Node<char>(c);
			obj.insertAfter(after, node);
		}
		if (choice == 4){
			obj.print();
		}
		if (choice == 5){
			std::cout << "enter a char :";

			std::cin >> c;
			Node<char> *first = new Node<char>(c);
			obj.insertFirst(first);
		}
		if (choice == 6){
			obj.reverse();
		}
		if (choice == 7){

			std::cout << "Enter a char : ";
			std::cin >> c;
			Node<char> *node = new Node<char>(c);
			obj.add(node);
		}
		if (choice == 8){
			obj.removeWithRecursive();
		}
	}
}
void inputInt(){
	int choice;
	LinkedList<int> obj;
	int input;
	int number;
	while (1){

		std::cout << "1_insert last \n2_remove \n3_insert after\n4_print\n5_insert first\n6_reverse\n7_add\n8_recursive remove\n";
		std::cin >> choice;
		if (choice == 1){
			int size;
			std::cout << "enter number of numbers : ";
			std::cin >> size;


			int i = 0;
			while (i < size)
			{
				std::cout << "enter a number : ";
				std::cin >> input;

				Node<int> *node = new Node<int>(input);

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

			std::cin >> number;

			Node<int> *node = new Node<int>(number);
			obj.insertAfter(after, node);
		}
		if (choice == 4){
			obj.print();
		}
		if (choice == 5){
			std::cout << "enter a number :";

			std::cin >> number;
			Node<int> *first = new Node<int>(number);
			obj.insertFirst(first);
		}
		if (choice == 6){
			obj.reverse();
		}
		if (choice == 7){

			std::cout << "Enter a number : ";
			std::cin >> number;
			Node<int> *node = new Node<int>(number);
			obj.add(node);
		}
		if (choice == 8){
			obj.removeWithRecursive();
		}
	}
}
void inputString(){
	int choice;
	LinkedList<std::string> obj;
	std::string input;
	std::string  str;
	while (1){

		std::cout << "1_insert last \n2_remove \n3_insert after\n4_print\n5_insert first\n6_reverse\n7_add\n8_recursive remove\n";
		std::cin >> choice;
		if (choice == 1){
			int size;
			std::cout << "enter number of numbers : ";
			std::cin >> size;


			int i = 0;
			while (i < size)
			{
				std::cout << "enter a string : ";
				std::cin >> input;

				Node<std::string> *node = new Node<std::string>(input);

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
			std::cout << "enter a string :";

			std::cin >> str;

			Node<std::string> *node = new Node<std::string>(str);
			obj.insertAfter(after, node);
		}
		if (choice == 4){
			obj.print();
		}
		if (choice == 5){
			std::cout << "enter a string :";

			std::cin >> str;
			Node<std::string> *first = new Node<std::string>(str);
			obj.insertFirst(first);
		}
		if (choice == 6){
			obj.reverse();
		}
		if (choice == 7){

			std::cout << "Enter a string : ";
			std::cin >> str;
			Node<std::string> *node = new Node<std::string>(str);
			obj.add(node);
		}
		if (choice == 8){
			obj.removeWithRecursive();
		}
	}
}
void inputDouble(){

}
////////////////////////
template <class T>
int main()
{
	
	system("color 4");
	int choice;
	std::cout << "what type of data do you want to put in list? \n1_char\n2_int\n3_string\n4_double";
	int dataType;
	std::cin >> dataType;
	

	if (dataType == 1){
		inputChar();
	}
	else if (dataType == 2){
		inputInt();
	}
	else if (dataType == 3){
		inputString();
		
	}
	else if (dataType == 4){
		inputDouble();
	}
	



	system("pause");
	return 0;
}
