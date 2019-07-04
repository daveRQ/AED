// AVL.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "AVL.h"
#include <iostream>

using namespace std;

int main() {
	// probar con  1 8 3 4 2 9 
	Avl<double> A;
	A.add(1);
	A.add(8);
	A.add(3);

	A.add(4);
	A.add(2);
	A.add(9);
	A.add(12);
	A.add(23);
	A.add(232);
	A.add(123);
	A.add(300);
	A.add(10);
	A.add(11);
	A.add(0);
	A.add(5);
	A.add(6);
	A.add(6.5);
	A.add(6.6);
	A.add(6.7);
	A.add(6.8);
	A.add(6.9);
	A.add(7.9);
	A.add(7.1);
	A.add(7.2);
	A.add(7.3);
	A.add(8.4);
	A.add(8.5);
	A.add(8.6);
	A.add(8.7);
	A.add(8.8);
	A.add(81);
	A.add(2.1);
	A.add(3.1);
	A.add(4.1);
	A.add(8.1);
	A.add(8.1);
	A.add(8.1);

	A.print();
	system("PAUSE");

	A.remove(4);
	A.remove(2);
	A.remove(9);
	A.remove(12);
	A.remove(23);
	A.remove(232);
	A.remove(123);
	A.remove(300);
	A.remove(10);
	A.remove(11);
	A.remove(0);
	A.remove(5);
	A.remove(6);
	A.remove(2);
	A.remove(9);
	A.remove(12);
	A.remove(23);
	A.remove(232);
	A.remove(123);
	A.remove(300);
	A.remove(10);
	A.remove(11);
	A.remove(6.6);
	A.remove(6.7);
	A.remove(6.8);
	A.remove(6.9);
	A.remove(7.9);
	A.remove(7.1);
	A.remove(7.2);
	A.remove(7.3);
	A.remove(8.4);
	A.remove(0);
	A.remove(5);
	A.remove(6);
	A.remove(6.5);
	A.remove(8);
	A.remove(4.1);
	A.remove(3.1);
	A.remove(2.1);
	A.remove(8.1);
	A.remove(8.7);
	//A.remove(9);
	A.remove(1);
	//A.add(10);
	//A.remove();
	A.print();

	system("PAUSE");
	return 0;
}

