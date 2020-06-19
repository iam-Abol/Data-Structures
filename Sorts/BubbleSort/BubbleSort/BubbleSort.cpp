
#include "stdafx.h"
#include <iostream>
class BubbleSort{
	int size;
	int *array;
public:
	BubbleSort(int size) :size(size){
		array = new int[this->size];
		for (int i = 0; i < this->size; i++){
			std::cin >> array[i];
		}
	
	}
	void sort(){
		int t;
		for (int i = 0; i < size; i++){
			for (int j = 0; j < size - i - 1; j++){
				if (array[j]>array[j + 1]){
					t = array[j];
					array[j] = array[j + 1];
					array[j + 1] = t;
				}
			}
		}
		print();
	}
	
	 void print(){
		for (int i = 0; i < size; i++){
			std::cout << array[i]<<" ";
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int size;
	std::cin >> size;
	BubbleSort obj(size);
	obj.sort();
	system("pause");
	return 0;
}

