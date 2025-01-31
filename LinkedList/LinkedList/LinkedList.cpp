// LinkedList.cpp: define el punto de entrada de la aplicación de consola.
//


#include "stdafx.h"
#include "LinkedListSorted.h"
#include "LinkedListFO.h"
#include "LinkedListP.h"
#include "LinkedListPM.h"

#include <iostream>

using namespace std;



int main()
{
	LinkedListFO<int, Less<int>> A;
	A.add(4);
	A.add(64);
	A.add(-2);
	A.print();


	compare<int> *p = new Less1<int>;
	LinkedListP<int> B(p);
	B.add(32);
	B.add(12);
	B.add(-2);
	B.print();


	bool (Compare<int>::* Vcmp)(int, int) = &Compare<int>::Less;
	LinkedListPM<int> C(Vcmp);

	system("PAUSE");
	return 0;
}

