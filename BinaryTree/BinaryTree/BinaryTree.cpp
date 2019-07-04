// BinaryTree.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "BinaryTree.h"
#include <iostream>

using namespace std;

int main()
{
	TreeB<int, Less<int>> B;
	B.add(3);
	B.add(1);
	B.add(8);
	B.add(4);
	B.add(9);
	B.add(2);
	B.print();
	B.remove(4);
	B.print();
	system("PAUSE");
	return 0;
}

