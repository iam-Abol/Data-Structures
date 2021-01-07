#include "stdafx.h"
#include <iostream>
void print(int *arr, int size){
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
void swap(int &a, int&b){
	int t = a;
	a = b;
	b = t;
}
void selectionSort(int *arr, int size){
	for (int i = 0; i < size; i++)
	{
		int j, k;
		j = k = i;
		for (;j<size;j++)
		{
			if (arr[j] < arr[k])
				k = j;
		}
		swap(arr[i], arr[k]);
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	std::cout << "enter the number of elements : ";
	std::cin >> n;
	std::cout << "enter the numbers : " << std::endl;
	int *number = new int[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> number[i];
	}
	selectionSort(number, n);
	print(number, n);
	delete[] number;
	return 0;
}

