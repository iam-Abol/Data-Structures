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
};
int _tmain(int argc, _TCHAR* argv[])
{
	int choice;
	
	
	Queue obj;
	std::cout << "1_size\n2_isEmpty\n3_print" << std::endl;
	while (1){
		std::cin >> choice;
		if (choice == 1)
			std::cout<<"size : "<<obj.getSize()<<std::endl;
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
			
	}




	std::cin.get();
	std::cin.get();
	return 0;
}

