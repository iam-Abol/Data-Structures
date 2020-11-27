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
			for (int i = 0; i < top; i++){
				heap[i] = temp[i];
			}
			heap[top] = element;
			top++;
		}
		else{
			heap[top] = element;
			top++;
		}
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

	return 0;
}

