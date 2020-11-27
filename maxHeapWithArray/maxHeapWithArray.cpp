#include "stdafx.h"
#include <iostream>
class Heap{
private:
	int *heap;
	int size, top;


public:
	Heap(){
		heap = new int[10];
		size = top = 0;
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

