
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
	
	void print(){
		for (int i = 0; i < top; i++){
			std::cout << array[i] << std::endl;
		}
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	
	system("pause");
	return 0;
}

