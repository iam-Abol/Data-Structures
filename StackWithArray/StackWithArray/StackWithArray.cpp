
#include "stdafx.h"
#include <iostream>
class StackWithArray{
	int *array;
	int size ;
	int top ;
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
	
	void print(){
		std::cout << "numbers : " << std::endl; 
		for (int i = 0; i < top; i++){
			std::cout << array[i] << std::endl;
		}
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	int choice = 0;
	StackWithArray obj;
	while (true){
		std::cout << "1_push\n2_print\n";
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
	}
	system("pause");
	return 0;
}

