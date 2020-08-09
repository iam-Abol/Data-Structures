#include "stdafx.h"
#include <iostream>


template <class Temp>
struct variable
{
	Temp value;
	bool isDeleted;
	variable(){
		value = 0;
		isDeleted = false;
	}
};

template <class Temp>
class DynamicArray{
	variable *Array ;
	int sizeOfArray ;
	int sizeOfdata;
public :
	DynamicArray(){
		Array = new variable[10];
		sizeOfArray = 10;
		sizeOfdata = 0;
	}
	
};
int _tmain(int argc, _TCHAR* argv[])
{


	std::cin.get();
	return 0;
}

