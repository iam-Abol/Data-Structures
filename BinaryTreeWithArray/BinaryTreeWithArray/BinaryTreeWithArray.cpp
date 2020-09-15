#include "stdafx.h"
#include <iostream>
class BinaryTree{
	int **array;
	int size;
public:
	BinaryTree(){
		size = 10;
		array = new int*[4];
		for (int i = 0; i < 4; i++){
			array[i] = new int[10];
		}
		// testing array
		//for (int i = 0; i < 4; i++){
		//	for (int j = 0; j < 10; j++){
		//		array[i][j] = (i + 1)*(j + 1);
		//	}
		//}
		//for (int i = 0; i < 4; i++){
		//	for (int j = 0; j < 10; j++){
		//		std::cout << array[i][j] << "\t";
		//	}
		//	std::cout << std::endl;
		//}

	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	BinaryTree obj;

	system("pause");
	return 0;
}

