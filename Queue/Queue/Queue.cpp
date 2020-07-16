#include "stdafx.h"
#include <iostream>
class Node{
public:
	int element;
	Node * next;
	Node(){
		next = NULL;
		element = 0;
	}
	Node(int element){
		this->element = element;
		next = NULL;
	}
};
class Queue{
	Node *head = new Node;
	int size = 0;

public:
	bool isEmpty(){
		if (size == 0)
			return true;
		else
			return false;
	}
	int getSize(){
		return size;
	}

	void print(){
		bool flag = isEmpty();
		if (flag == true)
			std::cout << "--> Queue is empty <--" << std::endl;
		else{

			std::cout << "elements : " << std::endl;
			Node*temp = head;
			while (temp){
				std::cout << temp->element << std::endl;
				temp = temp->next;
			}
		}

	}
	void enQueue(Node *newNode){
		if (isEmpty())
			head->element = newNode->element;
		else{
			Node *temp = head;
			while (temp->next)
				temp = temp->next;
			temp->next = newNode;

		}
		size++;
	}
	void deQueue(){
		if (isEmpty() == true){
			std::cout << "--> Queue is empty <--" << std::endl;
		}
		else if (size == 1){
			head->element = 0;
			size--;
		}
		else{
			head = head->next;
			size--;
		}

	}
	void front(){
		if (size == 0){
			std::cout << "--> Queue is empty <--" << std::endl;

		}
		else{
			std::cout << "front element : " << head->element << std::endl;
		}

	}
	void rear(){
		if (size == 0){
			std::cout << "--> Queue is empty <--" << std::endl;

		}
		else if (size == 1)
			std::cout << "rear element : " << head->element << std::endl;
		else {
			Node *temp = head;
			while (temp->next){
				temp = temp->next;
			}
			std::cout << "rear element : "<<temp->element<<std::endl;
		}
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	int choice;


	Queue obj;

	while (1){
		std::cout << "1_size\n2_isEmpty\n3_print\n4_enQueue\n5_deQueue\n6_front\n7_rear" << std::endl;
		std::cin >> choice;
		if (choice == 1)
			std::cout << "size : " << obj.getSize() << std::endl;
		else if (choice == 2){
			bool flag = obj.isEmpty();
			if (flag == true)
				std::cout << "true" << std::endl;
			else{
				std::cout << "false" << std::endl;
			}
		}
		else if (choice == 3)
			obj.print();
		else if (choice == 4){
			int numberOfNumbers;
			std::cout << "number of numbers : ";
			std::cin >> numberOfNumbers;
			for (int i = 0; i < numberOfNumbers; i++){
				int number;
				std::cout << "enter a number : ";
				std::cin >> number;
				Node *newNode = new Node(number);
				obj.enQueue(newNode);
			}
		}
		else if (choice == 5)
			obj.deQueue();
		else if (choice == 6)
			obj.front();


		else if (choice == 7){
			obj.rear();
			
		}
	}




	std::cin.get();
	std::cin.get();
	return 0;
}

