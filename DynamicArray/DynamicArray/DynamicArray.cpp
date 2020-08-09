#include "stdafx.h"
#include <iostream>
struct variable
{
	int value;
	bool isDeleted;
	variable(){
		value = 0;
		isDeleted = false;
	}
};
class DynamicArray{
	variable *Array = new variable[10];
	int sizeOfArray;
	int sizeOfdata;
public:
	DynamicArray(){
		sizeOfArray = 10;
		sizeOfdata = 0;
	}
	void print(){
		if (sizeOfdata == 0){
			std::cout << "--> Array is empty <--" << std::endl;
		}
		else{
			for (int i = 0; i < sizeOfdata; i++){
				if (Array[i].isDeleted == false)
					std::cout << Array[i].value << std::endl;
			}
		}

	}
};



int _tmain(int argc, _TCHAR* argv[])
{
	DynamicArray myArray;
	myArray.print();

	std::cin.get();
	return 0;
}

