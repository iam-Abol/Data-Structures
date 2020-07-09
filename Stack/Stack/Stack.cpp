

#include "stdafx.h"
#include <iostream>
#include <string>
class Node{
public:
	int element;
	Node *next;

	Node(int element){
		this->element = element;
	}
	Node(){}
};


class Stack{
	Node *head = new Node;
	int size = 0;
	void recursivePush(Node *temp, Node*newNode){
		if (!temp->next){
			temp->next = newNode;
		}
		else{
			return recursivePush(temp->next, newNode);
		}
		size++;
	}
public:


	void push(Node *newNode){
		if (size == 0){
			head->element = newNode->element;
			head->next = NULL;
			size++;
		}
		else{
			Node *temp;
			temp = head;
			recursivePush(temp, newNode);
		}
		
	}
	void print(){
		if (size == 0)
			std::cout << "--> stack is empty <--" << std::endl;
		else{
			std::cout << "elements : \n";
			Node *temp = head;
			int i = 0;
			while (temp){
				std::cout << temp->element ;
				temp = temp->next;
				if (i < size - 1){
					std::cout << " <--> ";
				}
				i++;
			}
			std::cout << std::endl;
		}

	}
	int pop(){
		int lastElement;
		if (size == 1){
			lastElement = head->element;
			head = nullptr;
			
			
		}
		else{
			Node *temp = head;
			while (temp->next->next){
				temp = temp->next;
			}
			lastElement = temp->next->element;
			temp->next = NULL;
		}
		size--;
		return lastElement;
	}
	void isEmpty(){
		if (size <= 0){
			std::cout << "--> stack is empty <--" << std::endl;
		}
		else{
			std::cout << "--> stack is not empty <--" << std::endl;
		}
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Stack obj;
	int choice;
	while (true){
		std::cout << "1_push\n2_print\n3_pop\n4_isEmpty\n";
		
		std::cin >> choice;
		if (choice == 1){
			int size;
			
			std::cout << "Enter the number of numbers : ";
			std::cin >> size;
			for (int i = 0; i < size; i++){
				int number;
				std::cout << "Enter a number : ";
				
				std::cin >> number;
				Node *newNode = new Node(number);
				obj.push(newNode);
				
			}

		}
		else if (choice == 2){
			obj.print();
		}
		else if(choice == 3){
			int lastElement = obj.pop();
			std::cout << "last element : " << lastElement << std::endl;
		}
		else if (choice == 4){
			obj.isEmpty();
		}
	}
	std::cin.get();
	std::cin.get();
	return 0;
}

