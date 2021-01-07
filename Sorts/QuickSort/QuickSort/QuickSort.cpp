#include "stdafx.h"
#include <iostream>
void print(int *number, int size){
	for (size_t i = 0; i < size; i++)
	{
		std::cout << number[i] << std::endl;
	}
}
void quickSort(int number[],int size, int start, int end){
	

}
int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	std::cout << "enter the size of array : ";
	std::cin >> n;
	int *number = new int[n];
	for (int i = 0; i < n; i++)
		std::cin >> number[i];

	quickSort(number,n ,0, n - 1);

	delete[] number;
	return 0;
}

