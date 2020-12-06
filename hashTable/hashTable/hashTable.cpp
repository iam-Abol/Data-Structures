#include "stdafx.h"
#include <iostream>
class Node{
public:
	int element;
	Node *next;
};
class HashTable{
	Node array[10];
public:

};
int hash(int key, int size){
	return key%size;
}
int _tmain(int argc, _TCHAR* argv[])
{

	return 0;
}

