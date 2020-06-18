#include "stdafx.h"
#include <iostream>

class InsertionSort{

	int n;
	int *array;
public:
	InsertionSort(int n) : n(n)
	{
		array = new int[this->n];
		for (int i = 0; i < n; i++){
			std::cin >> array[i];
		}
	}
	
	void sort(){
		int t;
		for (int i = 1; i < n; i++){
			for (int j = i; j>0; j--){
				if (array[j] < array[j - 1]){
					t = array[j];
					array[j] = array[j - 1];
					array[j - 1] = t;
				}
			}
		}
		print();
	}

	void print(){
		for (int i = 0; i < n; i++){
			std::cout << array[i]<<" ";
		}
		std::cout << std::endl;
	}
	~InsertionSort(){
		delete[] array;
	}
	
};

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	std::cin >> n;
	InsertionSort obj(n);
	obj.sort();

	system("pause");
	return 0;
}

