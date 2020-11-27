#include "stdafx.h"
#include <iostream>
#include <string>
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
		updateHeap();
	}
	
	void print(){
		for (int i = 0; i < top; i++)
			std::cout << i << "\t" << heap[i] << std::endl;
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
	void updateHeap(){
		if (top == 1){
			return;
		}
		int i = top;
		while (heap[i - 1] > heap[i / 2 - 1]){
			swap(heap[i - 1], heap[i / 2 - 1]);
			i /= 2;
			if (i == 1)
				return;
		}
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Heap heap;
	int number;
	int choice = 0;
	while (true)
	{

		std::cout << "enter a number : " << std::endl;
		std::cout << "1-insert\n2-print" << std::endl;
		system("color 2");

		std::cin >> choice;
		if (choice == 1){

			std::cout << "enter a number for insert : ";
			std::cin >> number;
			heap.insert(number);
		}
		else if (choice == 2){
			heap.print();

		}
	}

	return 0;
}

