#include "stdafx.h"
#include <iostream>

///////////////////////////////////////

struct variable
{
	int value;
	bool isDeleted= false;
	bool isNull= true;
	
};

///////////////////////////////////////

class DynamicArray{
	variable *Array = new variable[10];
	int sizeOfArray;
	int sizeOfdata;
public:
	DynamicArray(){
		sizeOfArray = 10;
		sizeOfdata = 0;
	}
	void add(int index,int number){
		if (index < sizeOfArray){

			Array[index].value = number;
			Array[index].isNull = false;
			sizeOfdata++;
		}
		else if(index>=sizeOfArray){
			variable *tempArray = new variable[sizeOfArray];
			int sizeOfTempArray = sizeOfArray;
			for (int i = 0; i < sizeOfArray; i++){
				tempArray[i] = Array[i];
			}
			while (sizeOfArray <= index)
				sizeOfArray *= 2;
			Array = new variable[sizeOfArray];
			for (int i = 0; i < sizeOfTempArray; i++){
				Array[i] = tempArray[i];
			}
			///////////////////////////////////////
			Array[index].value = number;
			Array[index].isNull = false;
			sizeOfdata++;
		}
		
	}
	void print(){
		if (sizeOfdata == 0){
			std::cout << "--> Array is empty <--" << std::endl;
		}

		else{
			for (int i = 0; i < sizeOfArray; i++){
				if (Array[i].isDeleted == false && Array[i].isNull == false)
					std::cout << i << " --> " << Array[i].value << std::endl;
			}
		}

	}
	~DynamicArray(){
		delete[] Array;
	}
};

///////////////////////////////////////

int _tmain(int argc, _TCHAR* argv[])
{
	DynamicArray myArray;
	int choice;
	while (true){
		std::cout << "1_add\n2_remove\n3_print\n";
		std::cin >> choice;
		if (choice == 1){
			int index,number;
			std::cout << "Enter the index : ";
			std::cin >> index;
			std::cout << "Enter a number : ";
			std::cin >> number;
			myArray.add(index,number);
		}
		else if (choice == 3){
			myArray.print();
		}
	}

	std::cin.get();
	return 0;
}

