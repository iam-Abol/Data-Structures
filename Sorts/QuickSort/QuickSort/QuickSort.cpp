#include "stdafx.h"
#include <iostream>
void print(int *number, int start, int end){
	for (size_t i = start; i < end; i++)
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
void quickSort(int *number, int start, int end){
	if (start == end || end<0)
		return;
	int p = start;
	int j = end - 1;
	for (int i = start; i <= j; i++)
	{
		if (number[i] > number[p]){
			while (number[j] > number[p]){
				j--;
				if (j<i)
					break;
			}
			if (i != j&&i < j)
				swap(number[i], number[j]);
		}
	}

	swap(number[p], number[j]);
	quickSort(number, start, j);
	quickSort(number, j+1, end);
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	std::cout << "enter the size of array : ";
	std::cin >> n;
	int *number = new int[n];
	for (int i = 0; i < n; i++)
		std::cin >> number[i];

	quickSort(number, 0, n);
	print(number, 0, n);
	delete[] number;
	return 0;
}
/*
9
50
70
60
90
40
80
10
20
30
*/