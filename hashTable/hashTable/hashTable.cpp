#include "stdafx.h"
#include <iostream>
#include <chrono>
class Node{
public:
	int element;
	Node *next;
	int size = 0;
	Node(){
		element = -1;
		next = NULL;
		size = 0;
	}
	Node(int number){
		element = number;
	}
	int find(int number){
		if (size == 0){
			return false;
		}
		else
		{
			Node* temp = this;
			while (temp&&temp->element <= number)
			{
				if (temp->element == number)
					return true;
				temp = temp->next;
			}
			return false;
		}
	}
	void print()
	{
		Node* temp = this;
		while (temp){
			std::cout << temp->element << "\t";
			temp = temp->next;
		}
		std::cout << std::endl;
	}


};
class HashTable{
	Node *array;
public:
	HashTable(){
		array = new Node[10];
	}
	void chaining(int newNumber){
		int index = hash(newNumber, 10);
		if (array[index].element == -1){
			array[index].element = newNumber;
		}
		else{
			Node* newNode = new Node(newNumber);
			Node* temp = &(array[index]);
			/*		if (temp->element > newNode->element){
						newNode->next = temp->next;
						temp->next = newNode;
						int element = temp->element;
						temp->element = newNode->element;
						newNode->element = element;
						}*/

			while (temp->next != NULL){
				temp = temp->next;
			}

			temp->next = newNode;






		}
		array[index].size++;
	}
	void add(int number){
		int index = hash(number);
		if (array[index].element == -1){
			array[index].element = number;
			std::cout << "added" << std::endl;
		}

		else
			std::cout << "this index is full" << std::endl;

	}
	void search(int number){
		int index = hash(number);
		bool result = array[index].find(number);
		if (result)
			std::cout << "the number is at hash" << std::endl;
		else
			std::cout << "the number isnot at hash" << std::endl;
	}
	void remove(int number){

	}
	void print(){
		for (int i = 0; i < 10; i++){
			array[i].print();
		}
	}
	~HashTable(){
		delete[] array;
	}
private:
	int hash(int key, int size = 10){
		return key%size;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	HashTable h;
	int choice = 0;
	while (true)
	{


		auto start = std::chrono::steady_clock::now();
		std::cout << "ENTER A NUBMER : " << std::endl;
		std::cout << R"(1-add
2-search
3-print
4-remove
)";
		std::cin >> choice;
		if (choice == 1){
			int number;
			std::cout << "enter a number for add : ";
			std::cin >> number;
			h.add(number);
		}
		else if (choice == 2){
			std::cout << "enter a number for search : ";
			int number;
			std::cin >> number;
			h.search(number);

		}
		else if (choice == 3){
			h.print();
		}
		else if (choice == 4){
			int number;
			std::cout << "enter a number for deleting : ";
			std::cin >> number;
			h.remove(number);
		}
		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double> d = end - start;
		std::cout << "time that is taken is : " << d.count() << std::endl;

	}

	return 0;
}

