

#include "stdafx.h"
#include <iostream>
#include <string>
class Node{
public:
	std::string element;
	Node *next;

	Node(std::string element){
		this->element = element;
	}
	Node(){}
};


class Stack{
	Node *head = new Node;
	int size = 0;
public:
	void print(){
		if (size == 0)
			std::cout << "--> stack is empty <--" << std::endl;
		else{
			std::cout << "elements : \n";
			Node *temp = head;
			int i = 0;
			while (temp){
				std::cout << temp->element << std::endl;
				temp = temp->next;
				if (i < size - 1){
					std::cout << " <-->";
				}
			}
			std::cout << std::endl;
		}

	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Stack obj;
	obj.print();


	std::cin.get();
	std::cin.get();
	return 0;
}

