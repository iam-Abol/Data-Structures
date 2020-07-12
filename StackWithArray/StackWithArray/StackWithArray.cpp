
#include "stdafx.h"
#include <iostream>
class StackWithArray{
	int *array;
	int size;
	int top;
public:
	StackWithArray(){
		array = new int[10];
		size = 10;
		top = 0;
	}
	void push(int newElement){
		if (top == size){
			int *temp = new int[size];
			for (int i = 0; i < size; i++){
				temp[i] = array[i];
			}
			size *= 2;
			array = new int[size];
			for (int i = 0; i < size / 2; i++){
				array[i] = temp[i];
			}
			array[top] = newElement;
			top++;
		}
		else{
			array[top] = newElement;
			top++;
		}
	}
	void isEmpty(){
		if (top == 0){
			std::cout << "--> stack is empty ! <--" << std::endl;
		}
		else{
			std::cout << "--> stack is not empty ! <--" << std::endl;
		}
	}
	void print(){
		std::cout << "numbers : " << std::endl;
		for (int i = 0; i < top; i++){
			std::cout << array[i] << std::endl;
		}
	}
	void topElement(){
		if (top == 0){
			std::cout << "--> stack is empty ! <--" << std::endl;
		}
		else{
			std::cout << "top element : " << array[top - 1] << std::endl;
		}

	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	int choice = 0;
	StackWithArray obj;
	while (true){
		std::cout << "1_push\n2_print\n3_isEmpty\n4_topElement\n";
		std::cin >> choice;
		if (choice == 1){
			std::cout << "enter a number :";
			int number;
			std::cin >> number;
			obj.push(number);
		}
		else if (choice == 2){
			obj.print();
		}
		else if (choice == 3){
			obj.isEmpty();
		}
		else if (choice == 4){
			obj.topElement();
		}
	}
	system("pause");
	return 0;
}

