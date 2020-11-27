#include "stdafx.h"
#include <iostream>
class Heap{
private:
	int *heap;
	int size, top;


public:
	Heap(){
		size = 10;
		heap = new int[size];
		top = 0;
	}
	void insert(int element){
		if (top == size){
			int *temp = new int[size];
			for (int i = 0; i < size; i++)
			{
				temp[i] = heap[i];
			}
			size *= 2;
			heap = new int[size];
			for (int i = 0; i < top; i++){
				heap[i] = temp[i];
			}
			heap[top] = element;
			top++;
			delete temp;
		}
		else{
			heap[top] = element;
			top++;
		}
	}
	void print(){
		for (int i = 0; i < top; i++)
			std::cout << i << "\t" << heap[i]<<std::endl;
	}
	~Heap(){
		delete[] heap;
	}
private:
	void swap(int &a, int &b){
		int temp = a;
		a = b;
		b = temp;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Heap h;
	int number;
	int choice = 0;
	while (true)
	{
		std::cout << "1-insert\n2-print" << std::endl;
		std::cin >> choice;
		if (choice == 1){

		}
		else if (choice == 2){

		}
	}

	return 0;
}

