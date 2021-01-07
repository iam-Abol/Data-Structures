#include "stdafx.h"
#include <iostream>
void print(int *number, int size){
	for (size_t i = 0; i < size; i++)
	{
		std::cout << number[i] << " ";
	}
	std::cout << std::endl;
}
void swap(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}
void quickSort(int *number, int size, int start, int end){
	int p = start;
	int j = end - 1;
	for (int i = start; i <= j; i++)
	{
		if (number[i] > number[p]){
			while (number[j] > number[p]){
				j--;
				if (i == j)
					break;
			}
			if (i != j&&i<j)
				swap(number[i], number[j]);
		}
		
	}
	swap(number[p], number[j - 1]);
	print(number, size);
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	std::cout << "enter the size of array : ";
	std::cin >> n;
	int *number = new int[n];
	for (int i = 0; i < n; i++)
		std::cin >> number[i];

	quickSort(number, n, 0, n);

	delete[] number;
	return 0;
}

