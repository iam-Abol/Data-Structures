#include "stdafx.h"
#include <iostream>
class BinaryTree{
	int **array;
	int size;
	int top;
public:
	BinaryTree(){
		size = 10;
		array = new int*[4];
		for (int i = 0; i < 4; i++){
			array[i] = new int[10];
		}
		top = 0;
		/*array[0][0] = 1;
		array[0][1] = 2;
		array[0][2] = 3;
		array[0][3] = 4;
		array[0][4] = 5;*/
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
	void add(int newElement){
	
	}
	void print(){
		if (top == 0){
			std::cout << "EMPTY" << std::endl;
		}
		else{
			for (int i = 0; i < top; i++){
				std::cout << array[0][i];
				if (i < top - 1){
					std::cout << " <---!---> ";
				}
			}
		}
	}
	~BinaryTree(){
		for (int i = 0; i < 4; i++){
			delete[] array[i];
		}
		delete[] array;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	BinaryTree obj;
	obj.print();
	system("pause");
	return 0;
}

